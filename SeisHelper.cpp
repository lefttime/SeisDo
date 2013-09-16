#include "SeisHelper.hpp"

#include "Scene.hpp"
#include "SeisDo.hpp"
#include "Canvas.hpp"
#include "Shared.hpp"
#include "DataManager.hpp"
#include "SectionConfigEditor.hpp"

#include <QDir>
#include <QLabel>
#include <QFileInfo>
#include <QStatusBar>
#include <QFileDialog>

class SeisHelper::SeisHelperPrivate
{
public:

  SeisHelperPrivate( SeisHelper* me, SeisDo* target ) : m_self( me ), m_target( target ) {
    m_sectionConfig._traceCount = 300;
    m_sectionConfig._timeInterval = 10;
    m_sectionConfig._indexes.resize( m_sectionConfig._traceCount );
    for( int idx = 0; idx < m_sectionConfig._traceCount; ++idx ) {
      m_sectionConfig._indexes[idx] = idx;
    }
    m_sectionConfig._timeRange = QVector2D(0, 2000);
  }

  void init() {
    m_scene = new Scene( m_self );
    m_target->canvas()->setScene( m_scene );

    initStatusBar();
  }

  void initStatusBar() {
    m_pickerInfo = new QLabel( tr( "DaoNo.: " ) + tr( "Offset: " ) + tr( "Time: " ) );
    m_segyfileInfo = new QLabel( QObject::tr( "SEGY file:" ) );
    m_datafileInfo = new QLabel( tr( "FirstArrival file:" ) );

    m_pickerInfo->setFrameShape( QLabel::StyledPanel );
    m_segyfileInfo->setFrameShape( QLabel::StyledPanel );
    m_datafileInfo->setFrameShape( QLabel::StyledPanel );

    m_target->statusBar()->addWidget( m_pickerInfo, 1 );
    m_target->statusBar()->addPermanentWidget( m_segyfileInfo );
    m_target->statusBar()->addPermanentWidget( m_datafileInfo );

    QObject::connect( m_target->canvas(), SIGNAL( infoPicking( const QString& ) ),
                      m_pickerInfo, SLOT( setText( const QString& ) ) );
  }

  void setSegyFileInfo( const QString& fileName ) {
    QFileInfo fileInfo( fileName );
    m_segyfileInfo->setText( QObject::tr( "SEGY file:" ) + fileInfo.fileName() );
    m_segyfileInfo->setToolTip( fileName );

  }

  SeisHelper*         m_self;
  SeisDo*             m_target;
  Scene*              m_scene;

  SectionConfig       m_sectionConfig;

  QLabel*             m_pickerInfo;
  QLabel*             m_segyfileInfo;
  QLabel*             m_datafileInfo;
};

SeisHelper::SeisHelper( SeisDo* target, QObject* parent )
  : QObject( parent ), _pd( new SeisHelperPrivate( this, target ) )
{
  _pd->init();
}

SeisHelper::~SeisHelper()
{
}

const SectionConfig&SeisHelper::sectionConfig() const
{
  return _pd->m_sectionConfig;
}

void SeisHelper::setSectionConfig( const SectionConfig& sectionConfig )
{
  DataManager* dataManager = _pd->m_target->canvas()->dataManager();
  if( dataManager ) {
    if( _pd->m_sectionConfig._indexes != sectionConfig._indexes ||
        _pd->m_sectionConfig._timeRange != sectionConfig._timeRange ||
        _pd->m_sectionConfig._traceCount != sectionConfig._traceCount ) {
      dataManager->setSectionConfig( sectionConfig );
    }
  }
  _pd->m_sectionConfig = sectionConfig;
}

bool SeisHelper::open()
{
  QString fileName =
      QFileDialog::getOpenFileName( _pd->m_target, tr( "Open File" ),
                                    QDir::currentPath(),
                                    tr( "Seg-Y (*.sgy *.segy)" ) );
  _pd->setSegyFileInfo( fileName );
  if( !fileName.isEmpty() ) {
    DataManager* dataManager = new DataManager( fileName );
    dataManager->setSectionConfig( _pd->m_sectionConfig );
    _pd->m_target->canvas()->setDataManager( dataManager );
    return true;
  }

  return false;
}

void SeisHelper::save()
{
}

void SeisHelper::saveAs()
{
}

void SeisHelper::load()
{
}

void SeisHelper::close()
{
  _pd->m_target->canvas()->setScene( 0 );
  delete _pd->m_scene;
  _pd->m_scene = 0;
}

void SeisHelper::next()
{
  DataManager* dataManager = _pd->m_target->canvas()->dataManager();
  if( dataManager ) {
    qint32 lastIndex = _pd->m_sectionConfig._indexes.last();
    if( lastIndex < dataManager->totalTraces()-1 ) {
      qint32 validCount = qMin( dataManager->totalTraces()-lastIndex-1, _pd->m_sectionConfig._traceCount );
      QVector<qint32> indexes;
      for( int idx = 0; idx < validCount; ++idx ) {
        qint32 traceIdx = _pd->m_sectionConfig._indexes.at( idx ) + _pd->m_sectionConfig._traceCount;
        if( traceIdx > dataManager->totalTraces()-1 ) {
          break;
        }
        indexes << traceIdx;
      }
      _pd->m_sectionConfig._indexes = indexes;
      dataManager->setSectionConfig( _pd->m_sectionConfig );
    }
  }
}

void SeisHelper::previous()
{
  DataManager* dataManager = _pd->m_target->canvas()->dataManager();
  qint32 startIndex = _pd->m_sectionConfig._indexes.first();
  if( dataManager && startIndex ) {
    startIndex = qMax( 0, startIndex-_pd->m_sectionConfig._traceCount );
    qint32 validCount = qMin( dataManager->totalTraces(), _pd->m_sectionConfig._traceCount );
    QVector<qint32> indexes;
    for( int idx = 0; idx < validCount; ++idx ) {
      indexes << startIndex + idx;
    }
    _pd->m_sectionConfig._indexes = indexes;
    dataManager->setSectionConfig( _pd->m_sectionConfig );
  }
}

void SeisHelper::sectionEdit()
{
  SectionConfigEditor editor( _pd->m_sectionConfig, _pd->m_target );
  if( editor.exec() == QDialog::Accepted ) {
    setSectionConfig( editor.config() );
  }
}
