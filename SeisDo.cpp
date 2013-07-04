#include "SeisDo.h"
#include "ui_SeisDo.h"

class SeisDo::SeisDoPrivate
{
public:

  SeisDoPrivate( SeisDo* me ) : m_self( me ) {
    m_ui.setupUi( m_self );
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
