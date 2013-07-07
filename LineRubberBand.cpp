#include "LineRubberBand.hpp"

#include <QPainter>
#include <QWidget>

class LineRubberBand::LineRubberBandPrivate
{
public:

  LineRubberBandPrivate( LineRubberBand* me ) : m_self( me )  {

  }

  LineRubberBand*         m_self;
  QPoint                  m_firstPoint;
  QPoint                  m_secondPoint;
};

LineRubberBand::LineRubberBand( const PlotConfig& plotConfig )
  : AbstractShapeItem( plotConfig ), _pd( new LineRubberBandPrivate( this ) )
{
  hide();
}

LineRubberBand::~LineRubberBand()
{
}

void LineRubberBand::setFirstPoint( const QPoint& point )
{
  _pd->m_firstPoint = point;
  _pd->m_secondPoint = point;
}

void LineRubberBand::setSecondPoint( const QPoint& point )
{
  _pd->m_secondPoint = point;
}

void LineRubberBand::doPaint( QPainter* painter )
{
  painter->save();

  QPen pen( Qt::red, 2, Qt::DashLine );
  painter->setPen( pen );
  painter->setRenderHint( QPainter::Antialiasing );
  painter->drawLine( _pd->m_firstPoint, _pd->m_secondPoint );

  painter->restore();
}
