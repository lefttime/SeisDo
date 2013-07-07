#include "TraceItem.hpp"
#include "UniformData2D.hpp"

class TraceItem::TraceItemPrivate
{
public:

  TraceItemPrivate( TraceItem* me, const UniformData2D& data )
    : m_self( me ), m_data( data ) {
  }

  TraceItem*            m_self;
  const UniformData2D&  m_data;
};

TraceItem::TraceItem( const PlotConfig& plotConfig, const UniformData2D& data )
  : AbstractShapeItem( plotConfig ), _pd( new TraceItemPrivate( this, data ) )
{
}

TraceItem::~TraceItem()
{
}

void TraceItem::doPaint( QPainter* painter )
{
  Q_UNUSED( painter );
  if( _pd->m_data.data().isEmpty() ) {
    return;
  }
}
