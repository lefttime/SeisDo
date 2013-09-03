#include "SeisHelper.hpp"

#include "Scene.hpp"
#include "SeisDo.hpp"
#include "Canvas.hpp"
#include "DataManager.hpp"

#include <QDir>
#include <QLabel>
#include <QStatusBar>
#include <QFileDialog>

class SeisHelper::SeisHelperPrivate
{
public:

  SeisHelperPrivate( SeisHelper* me, SeisDo* target ) : m_self( me ), m_target( target ) {
  }

  void init() {
    m_scene = new Scene( m_self );
    m_target->canvas()->setScene( m_scene );

    initStatusBar();
  }

  void initStatusBar() {
    m_pickerInfo = new QLabel( tr( "DaoNo.: " ) + tr( "Offset: " ) + tr( "Time: " ) );
    m_segyfileInfo = new QLabel( tr( "SEGY file:" ) );
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

  SeisHelper*         m_self;
  SeisDo*             m_target;
  Scene*              m_scene;

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

bool SeisHelper::open()
{
  QString fileName =
    QFileDialog::getOpenFileName( _pd->m_target, tr( "Open File" ),
                                  QDir::currentPath(),
                                  tr( "Seg-Y (*.sgy *.segy)" ) );
  if( !fileName.isEmpty() ) {
    DataManager* dataManager = new DataManager( fileName );
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
//  _pd->m_data = _pd->m_dataManager.prepareData( 1 );
}

void SeisHelper::previous()
{
//  _pd->m_data = _pd->m_dataManager.prepareData( 0 );
}
