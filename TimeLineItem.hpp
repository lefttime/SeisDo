#ifndef TIMELINEITEM_HPP
#define TIMELINEITEM_HPP

#include "AbstractShapeItem.hpp"

class TimeLineItem : public AbstractShapeItem
{
public:

  TimeLineItem();
  ~TimeLineItem();

protected:

  virtual void doPaint( QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget=0 );

private:

  class TimeLineItemPrivate;
  QScopedPointer<TimeLineItemPrivate>         _pd;
};

#endif // TIMELINEITEM_HPP