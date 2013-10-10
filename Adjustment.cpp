#include "Adjustment.hpp"
#include "ui_Adjustment.h"

class Adjustment::AdjustmentPrivate
{
public:

  AdjustmentPrivate( Adjustment* me ) : m_self( me ) {
    m_ui.setupUi( m_self );
  }

  Adjustment*         m_self;
  Ui::Adjustment      m_ui;
};

Adjustment::Adjustment( QWidget* parent )
  : QWidget( parent ), _pd( new AdjustmentPrivate( this ) )
{
}

Adjustment::~Adjustment()
{
}

int Adjustment::value() const
{
  return _pd->m_ui.spinBox->value();
}
