#include "Legend.hpp"

class Legend::LegendPrivate
{
public:

  LegendPrivate( Legend* me ) : m_self( me ) {
  }

  Legend*         m_self;
  QRectF          m_plotArea;
};

Legend::Legend( QWidget* parent ) : QLabel( parent ), _pd( new LegendPrivate( this ) )
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
  _pd->m_plotArea = plotArea;
}

void Legend::changePlotArea( QRectF plotArea )
{
  Q_UNUSED( plotArea );
  setPlotArea( plotArea );
}
