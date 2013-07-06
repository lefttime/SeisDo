#include "SeisDo.hpp"
#include "ui_SeisDo.h"

#include "Scene.hpp"
#include "Translator.hpp"

class SeisDo::SeisDoPrivate
{
public:

  SeisDoPrivate( SeisDo* me ) : m_self( me ) {
    m_ui.setupUi( m_self );

    QActionGroup* actionGroup = new QActionGroup( m_self );
    actionGroup->addAction( m_ui.actionChinese );
    actionGroup->addAction( m_ui.actionEnglish );
    actionGroup->setExclusive( true );
  }

  void init() {
    m_scene = new Scene( m_self );
    m_ui.view->setScene( m_scene );

    QObject::connect( m_ui.view, SIGNAL( plotAreaChanged( QRectF ) ),
                      m_ui.top, SLOT( changePlotArea( QRectF ) ) );
    QObject::connect( m_ui.view, SIGNAL( plotAreaChanged( QRectF ) ),
                      m_ui.left, SLOT( changePlotArea( QRectF ) ) );
    QObject::connect( m_ui.view, SIGNAL( plotAreaChanged( QRectF ) ),
                      m_ui.right, SLOT( changePlotArea( QRectF ) ) );

    m_ui.top->setDirection( AxisLegend::North );
    m_ui.left->setDirection( AxisLegend::West );
    m_ui.right->setDirection( AxisLegend::East );

    PlotConfig plotConfig;
    plotConfig._plotArea = QRectF(QPointF(0, 0), QPointF(1024, 1024));
    m_scene->setPlotConfig( plotConfig );
  }

  SeisDo*         m_self;
  Ui::SeisDoClass m_ui;

  Scene*          m_scene;
};

SeisDo::SeisDo( QWidget* parent, Qt::WFlags flags )
  : QMainWindow( parent, flags ), _pd( new SeisDoPrivate( this ) )
{
  _pd->init();
}

SeisDo::~SeisDo()
{
}

void SeisDo::changeEvent( QEvent* event )
{
  if( event->type() == QEvent::LanguageChange ) {
    _pd->m_ui.retranslateUi( this );
  }

  QWidget::changeEvent( event );
}

void SeisDo::on_actionChinese_triggered()
{
  theTranslator->setLanguageType( Translator::Chinese );
}

void SeisDo::on_actionEnglish_triggered()
{
  theTranslator->setLanguageType( Translator::English );
}
