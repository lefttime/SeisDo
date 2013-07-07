#include "TimeLineItem.hpp"

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
  Q_UNUSED( painter );
}
