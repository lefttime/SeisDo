#include "TimeLineItem.hpp"

#include <QPainter>

class TimeLineItem::TimeLineItemPrivate
{
public:

  TimeLineItemPrivate( TimeLineItem* me ) : m_self( me ) {
  }

  TimeLineItem*         m_self;
};

TimeLineItem::TimeLineItem( const PlotConfig& plotConfig )
  : AbstractShapeItem( plotConfig ), _pd( new TimeLineItemPrivate( this ) )
{
}

TimeLineItem::~TimeLineItem()
{
}

void TimeLineItem::doPaint( QPainter* painter )
{
  QRect plotArea = plotConfig()._plotArea;
  for( int idx = plotArea.top(); idx < plotArea.bottom(); idx += 100 ) {
    painter->drawLine( QPointF(plotArea.left(), idx), QPointF(plotArea.right(), idx) );
  }
}
