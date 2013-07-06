#include "TimeLineItem.hpp"

class TimeLineItem::TimeLineItemPrivate
{
public:

  TimeLineItemPrivate( TimeLineItem* me ) : m_self( me ) {

  }

  TimeLineItem*         m_self;
};

TimeLineItem::TimeLineItem() : AbstractShapeItem(), _pd( new TimeLineItemPrivate( this ) )
{
}

TimeLineItem::~TimeLineItem()
{
}

void TimeLineItem::doPaint( QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget )
{
  Q_UNUSED( painter );
  Q_UNUSED( option );
  Q_UNUSED( widget );
}
