#include "SeisDo.hpp"
#include "ui_SeisDo.h"

#include "Canvas.hpp"
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
    m_helper = new SeisHelper( m_self );
    m_self->on_actionEnablePicking_triggered();
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
  return _pd->m_ui.plot;
}

void SeisDo::changeEvent( QEvent* event )
{
  if( event->type() == QEvent::LanguageChange ) {
    _pd->m_ui.retranslateUi( this );
  }

  QWidget::changeEvent( event );
}

void SeisDo::on_actionOpen_triggered()
{
  if( _pd->m_helper->open() ) {
    _pd->m_ui.actionOpen->setEnabled( false );
    _pd->m_ui.actionSave->setEnabled( true );
    _pd->m_ui.actionSaveAs->setEnabled( true );
    _pd->m_ui.actionClose->setEnabled( true );
  }
}

void SeisDo::on_actionClose_triggered()
{
  _pd->m_helper->close();
  _pd->m_ui.actionOpen->setEnabled( true );
  _pd->m_ui.actionSave->setEnabled( false );
  _pd->m_ui.actionSaveAs->setEnabled( false );
  _pd->m_ui.actionClose->setEnabled( false );
}

void SeisDo::on_actionEnablePicking_triggered()
{
  bool enabled = _pd->m_ui.actionEnablePicking->isChecked();
  _pd->m_helper->setPickingEnabled( enabled );
  canvas()->canvas()->setCursor( enabled ? Qt::CrossCursor : Qt::ArrowCursor );
}

void SeisDo::on_actionChinese_triggered()
{
  theTranslator->setLanguageType( Translator::Chinese );
}

void SeisDo::on_actionEnglish_triggered()
{
  theTranslator->setLanguageType( Translator::English );
}

void SeisDo::on_actionPrevious_triggered()
{
  _pd->m_helper->previous();
}

void SeisDo::on_actionNext_triggered()
{
  _pd->m_helper->next();
}

void SeisDo::on_actionOption_triggered()
{
  _pd->m_helper->sliceEdit();
}
