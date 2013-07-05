#include "Legend.hpp"

class Legend::LegendPrivate
{
  LegendPrivate( Legend* me ) : m_self( me ) {
  }

  Legend*         m_self;
};

Legend::Legend( QWidget* parent ) : QLabel( parent )
{
}

Legend::~Legend()
{
}
