#ifndef TIMELINEITEM_HPP
#define TIMELINEITEM_HPP

#include "AbstractShapeItem.hpp"

class TimeLineItem : public AbstractShapeItem
{
public:

  TimeLineItem( const PlotConfig& plotConfig );
  ~TimeLineItem();

protected:

  virtual void doPaint( QPainter* painter );

private:

  class TimeLineItemPrivate;
  QScopedPointer<TimeLineItemPrivate>         _pd;
};

#endif // TIMELINEITEM_HPP