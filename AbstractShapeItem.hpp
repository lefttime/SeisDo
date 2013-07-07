#ifndef ABSTRACTSHAPEITEM_HPP
#define ABSTRACTSHAPEITEM_HPP

#include "Shared.hpp"

#include <QRectF>
#include <QScopedPointer>

class QPainter;
class QPaintEvent;

class AbstractShapeItem
{
public:

  AbstractShapeItem( const PlotConfig& plotConfig );
  virtual ~AbstractShapeItem();

  const PlotConfig& plotConfig() const;

  void show();
  void hide();

  void render( QPainter* painter );

protected:

  virtual void doPaint( QPainter* painter )=0;

private:

  class AbstractShapeItemPrivate;
  QScopedPointer<AbstractShapeItemPrivate>         _pd;
};

#endif // ABSTRACTSHAPEITEM_HPP