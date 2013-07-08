#include "SeisHelper.hpp"

#include "Scene.hpp"
#include "Canvas.hpp"
#include "SeisDo.hpp"
#include "DataManager.hpp"

#include "TraceItem.hpp"
#include "TimeLineItem.hpp"

#include <QStatusBar>
#include <QLabel>

class SeisHelper::SeisHelperPrivate
{
public:

  SeisHelperPrivate( SeisHelper* me, SeisDo* target ) : m_self( me ), m_target( target ) {
  }

  void init() {
    m_scene = new Scene( m_self );
    m_target->canvas()->setScene( m_scene );

    QObject::connect( m_target->canvas(), SIGNAL( showPickingInfo( const QString&, int ) ),
                      m_target->statusBar(), SLOT( showMessage( const QString&, int ) ) );

    m_timeLine = new TimeLineItem( m_scene->plotConfig() );
    m_scene->addItem( m_timeLine );

    // TODO: delete later
    testForStatusBar();

    // TODO: delete later
    m_data = m_dataManager.prepareData();
    m_traceItem = new TraceItem( m_scene->plotConfig(), m_data );
    m_scene->addItem( m_traceItem );
  }

  void testForStatusBar() {
    QStatusBar* statusBar = m_target->statusBar();
    if( statusBar ) {
      QLabel* label0 = new QLabel;//( "DaoNo: 149\tOffset: 713\tTime: 8" );
      label0->setSizePolicy( QSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding) );
      label0->setFrameShape( QFrame::Panel );
      label0->setFrameShadow( QFrame::Sunken );
      statusBar->addWidget( label0, 1 );

      QLabel* label1 = new QLabel( "SEGY file: example_2d.sgy" );
      label1->setMinimumWidth( 200 );
      label1->setFrameShape( QFrame::Panel );
      label1->setFrameShadow( QFrame::Sunken );
      statusBar->addPermanentWidget( label1 );

      QLabel* label2 = new QLabel( "FirstArrival file:       " );
      label2->setMinimumWidth( 200 );
      label2->setFrameShape( QFrame::Panel );
      label2->setFrameShadow( QFrame::Sunken );
      statusBar->addPermanentWidget( label2 );

      statusBar->setSizeGripEnabled( false );
    }
  }

  SeisHelper*         m_self;
  SeisDo*             m_target;
  DataManager         m_dataManager;

  Scene*              m_scene;
  TraceItem*          m_traceItem;
  TimeLineItem*       m_timeLine;

  UniformData2D       m_data;

};

SeisHelper::SeisHelper( SeisDo* target, QObject* parent )
  : QObject( parent ), _pd( new SeisHelperPrivate( this, target ) )
{
  _pd->init();
}

SeisHelper::~SeisHelper()
{
}

void SeisHelper::next()
{
  _pd->m_data = _pd->m_dataManager.prepareData( 1 );
}

void SeisHelper::previous()
{
  _pd->m_data = _pd->m_dataManager.prepareData( 0 );
}