#include "AbstractShapeItem.hpp"

class AbstractShapeItem::AbstractShapeItemPrivate
{
public:

  AbstractShapeItemPrivate( AbstractShapeItem* me, const PlotConfig& plotConfig )
    : m_self( me ), m_plotConfig( plotConfig ), m_display( true ) {
  }

  AbstractShapeItem*         m_self;
  const PlotConfig&          m_plotConfig;

  bool                       m_display;
};

AbstractShapeItem::AbstractShapeItem( const PlotConfig& plotConfig )
  : _pd( new AbstractShapeItemPrivate( this, plotConfig ) )
{
}

AbstractShapeItem::~AbstractShapeItem()
{
}

const PlotConfig& AbstractShapeItem::plotConfig() const
{
  return _pd->m_plotConfig;
}

void AbstractShapeItem::show()
{
  _pd->m_display = true;
}

void AbstractShapeItem::hide()
{
  _pd->m_display = false;
}

void AbstractShapeItem::render( QPainter* painter )
{
  if( _pd->m_display ) {
    doPaint( painter );
  }
}
