#include "SeisHelper.hpp"

#include "SeisDo.hpp"
#include "Canvas.hpp"
#include "DataManager.hpp"

#include <QLabel>
#include <QStatusBar>

class SeisHelper::SeisHelperPrivate
{
public:

  SeisHelperPrivate( SeisHelper* me, SeisDo* target ) : m_self( me ), m_target( target ) {
  }

  void init() {
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
  QLabel*             m_pickerInfo;
  QLabel*             m_segyfileInfo;
  QLabel*             m_datafileInfo;

  UniformData2D       m_data;
  DataManager         m_dataManager;
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
//  _pd->m_data = _pd->m_dataManager.prepareData( 1 );
}

void SeisHelper::previous()
{
//  _pd->m_data = _pd->m_dataManager.prepareData( 0 );
}
