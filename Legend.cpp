#include "Legend.hpp"

class Legend::LegendPrivate
{
public:

  LegendPrivate( Legend* me ) : m_self( me ) {
  }

  Legend*         m_self;
  QRectF          m_plotArea;
};

Legend::Legend( QWidget* parent ) : QLabel( parent )
{
}

Legend::~Legend()
{
}

const QRectF&Legend::plotArea() const
{
  return _pd->m_plotArea;
}

void Legend::setPlotArea( const QRectF& plotArea )
{
}

void Legend::changePlotArea( QRectF plotArea )
{
  Q_UNUSED( plotArea );
  setPlotArea( plotArea );
}
