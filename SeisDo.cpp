#include "SeisDo.hpp"
#include "ui_SeisDo.h"

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

  SeisDo*         m_self;
  Ui::SeisDoClass m_ui;
};

SeisDo::SeisDo( QWidget* parent, Qt::WFlags flags )
  : QMainWindow( parent, flags ), _pd( new SeisDoPrivate( this ) )
{
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
