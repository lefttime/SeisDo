#include "AbstractShapeItem.hpp"

class AbstractShapeItem::AbstractShapeItemPrivate
{
public:

  AbstractShapeItemPrivate( AbstractShapeItem* me ) : m_self( me ) {
  }

  AbstractShapeItem*         m_self;
};

AbstractShapeItem::AbstractShapeItem() : QAbstractGraphicsShapeItem(), _pd( new AbstractShapeItemPrivate( this ) )
{
}

AbstractShapeItem::~AbstractShapeItem()
{
}

void AbstractShapeItem::paint( QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget )
{
  doPaint( painter, option, widget );
}
