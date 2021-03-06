#include "SeisDo.hpp"
#include "ui_SeisDo.h"

#include "Translator.hpp"
#include "SeisHelper.hpp"

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

  ~SeisDoPrivate() {
    delete m_helper;
  }

  void init() {
    QObject::connect( m_ui.view, SIGNAL( plotAreaChanged( QRectF ) ),
                      m_ui.top, SLOT( changePlotArea( QRectF ) ) );
    QObject::connect( m_ui.view, SIGNAL( plotAreaChanged( QRectF ) ),
                      m_ui.left, SLOT( changePlotArea( QRectF ) ) );
    QObject::connect( m_ui.view, SIGNAL( plotAreaChanged( QRectF ) ),
                      m_ui.right, SLOT( changePlotArea( QRectF ) ) );

    m_ui.top->setDirection( AxisLegend::North );
    m_ui.left->setDirection( AxisLegend::West );
    m_ui.right->setDirection( AxisLegend::East );

    m_helper = new SeisHelper( m_self );
  }

  SeisDo*         m_self;
  Ui::SeisDoClass m_ui;

  SeisHelper*     m_helper;
};

SeisDo::SeisDo( QWidget* parent, Qt::WFlags flags )
  : QMainWindow( parent, flags ), _pd( new SeisDoPrivate( this ) )
{
  _pd->init();
}

SeisDo::~SeisDo()
{
}

Canvas* SeisDo::canvas()
{
  return _pd->m_ui.view;
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

void SeisDo::on_actionNext_triggered()
{
  _pd->m_helper->next();
}

void SeisDo::on_actionPrevious_triggered()
{
  _pd->m_helper->previous();
}
