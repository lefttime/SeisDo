#ifndef TRACEITEM_HPP
#define TRACEITEM_HPP

#include "AbstractShapeItem.hpp"

class UniformData2D;

class TraceItem : public AbstractShapeItem
{
public:

  TraceItem( const UniformData2D& data );
  ~TraceItem();

protected:

  virtual void doPaint( QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget=0 );

private:

  class TraceItemPrivate;
  QScopedPointer<TraceItemPrivate>         _pd;
};

#endif // TRACEITEM_HPP