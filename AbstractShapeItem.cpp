#include "AbstractShapeItem.hpp"

class AbstractShapeItem::AbstractShapeItemPrivate
{
public:

  AbstractShapeItemPrivate( AbstractShapeItem* me, const PlotConfig& plotConfig )
    : m_self( me ), m_plotConfig( plotConfig ) {
  }

  AbstractShapeItem*         m_self;
  const PlotConfig&          m_plotConfig;
};

AbstractShapeItem::AbstractShapeItem( const PlotConfig& plotConfig )
  : _pd( new AbstractShapeItemPrivate( this, plotConfig ) )
{
}

AbstractShapeItem::~AbstractShapeItem()
{
}

void AbstractShapeItem::render( QPainter* painter, QPaintEvent* event )
{
  Q_UNUSED( event );
  doPaint( painter );
}
