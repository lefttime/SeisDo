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
    m_sliceConfig._traceCount = 300;
    m_sliceConfig._timeInterval = 10;
    m_sliceConfig._indexes.resize( m_sliceConfig._traceCount );
    for( int idx = 0; idx < m_sliceConfig._traceCount; ++idx ) {
      m_sliceConfig._indexes[idx] = idx;
    }
    m_sliceConfig._timeRange = QVector2D(0, 2000);
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

  SliceConfig adjustedSliceConfig( const SliceConfig& config ) {
    SliceConfig result = config;
    int span = result._indexes.count() - result._traceCount;
    if( span > 0 ) {
      result._indexes = result._indexes.mid( 0, result._traceCount );
    } else if( span < 0 ) {
      span = qAbs( span );
      for( int idx = 0; idx < span; ++idx ) {
        result._indexes << result._indexes.last() + 1;
      }
    }
    return result;
  }

  SeisHelper*         m_self;
  SeisDo*             m_target;
  Scene*              m_scene;

  SliceConfig         m_sliceConfig;

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

const SliceConfig& SeisHelper::sliceConfig() const
{
  return _pd->m_sliceConfig;
}

void SeisHelper::setSliceConfig( const SliceConfig& sliceConfig )
{
  DataManager* dataManager = _pd->m_target->canvas()->dataManager();
  if( dataManager ) {
    if( _pd->m_sliceConfig != sliceConfig ) {
      dataManager->setSliceConfig( _pd->adjustedSliceConfig( sliceConfig ) );
    }
  }
  _pd->m_sliceConfig = _pd->adjustedSliceConfig( sliceConfig );
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
    dataManager->setSliceConfig( _pd->m_sliceConfig );
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


  _pd->m_target->canvas()->setDataManager( 0 );
}

void SeisHelper::setPickingEnabled( bool enabled )
{
  _pd->m_target->canvas()->enablePicking( enabled );
}

void SeisHelper::next()
{
  DataManager* dataManager = _pd->m_target->canvas()->dataManager();
  if( dataManager ) {
    qint32 lastIndex = _pd->m_sliceConfig._indexes.last();
    if( lastIndex < dataManager->totalTraces()-1 ) {
      qint32 validCount = qMin( dataManager->totalTraces()-lastIndex-1, _pd->m_sliceConfig._traceCount );
      QVector<qint32> indexes;
      for( int idx = 0; idx < validCount; ++idx ) {
        qint32 traceIdx = _pd->m_sliceConfig._indexes.at( idx ) + _pd->m_sliceConfig._traceCount;
        if( traceIdx > dataManager->totalTraces()-1 ) {
          break;
        }
        indexes << traceIdx;
      }
      _pd->m_sliceConfig._indexes = indexes;
      dataManager->setSliceConfig( _pd->m_sliceConfig );
    }
  }
}

void SeisHelper::previous()
{
  DataManager* dataManager = _pd->m_target->canvas()->dataManager();
  qint32 startIndex = _pd->m_sliceConfig._indexes.first();
  if( dataManager && startIndex ) {
    startIndex = qMax( 0, startIndex-_pd->m_sliceConfig._traceCount );
    qint32 validCount = qMin( dataManager->totalTraces(), _pd->m_sliceConfig._traceCount );
    QVector<qint32> indexes;
    for( int idx = 0; idx < validCount; ++idx ) {
      indexes << startIndex + idx;
    }
    _pd->m_sliceConfig._indexes = indexes;
    dataManager->setSliceConfig( _pd->m_sliceConfig );
  }
}

void SeisHelper::sectionEdit()
{
  SectionConfigEditor editor( _pd->m_sliceConfig, _pd->m_target );
  if( editor.exec() == QDialog::Accepted ) {
    setSliceConfig( editor.config() );
  }
}
