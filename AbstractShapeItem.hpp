#ifndef ABSTRACTSHAPEITEM_HPP
#define ABSTRACTSHAPEITEM_HPP

#include <QAbstractGraphicsShapeItem>

class AbstractShapeItem : public QAbstractGraphicsShapeItem
{
public:

  AbstractShapeItem();
  ~AbstractShapeItem();

protected:

  virtual void doPaint( QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget=0 )=0;

  virtual void paint( QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget=0 );

private:

  class AbstractShapeItemPrivate;
  QScopedPointer<AbstractShapeItemPrivate>         _pd;
};

#endif // ABSTRACTSHAPEITEM_HPP