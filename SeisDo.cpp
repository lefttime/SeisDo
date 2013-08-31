#include "SeisDo.hpp"
#include "ui_SeisDo.h"

#include "Canvas.hpp"
#include "Translator.hpp"
#include "SeisHelper.hpp"
#include "DataManager.hpp"

#include <QDir>
#include <QFileDialog>

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

void SeisDo::on_actionOpenFile_triggered()
{
  QString fileName = QFileDialog::getOpenFileName( this, tr("Open File"),
                                                   QDir::currentPath(),
                                                   tr("Seg-Y (*.sgy *.segy)"));
  if( !fileName.isEmpty() ) {
    DataManager dataManager( fileName );
  }
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
