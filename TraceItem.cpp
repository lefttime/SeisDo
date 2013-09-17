#include "TraceItem.hpp"

class TraceItem::TraceItemPrivate
{
public:

  TraceItemPrivate( TraceItem* me ) : m_self( me ) {
  }

  TraceItem*            m_self;
  QPointF               m_offset;
};

TraceItem::TraceItem() : QwtPlotCurve(), _pd( new TraceItemPrivate( this ) )
{
}

TraceItem::~TraceItem()
{
}

void TraceItem::translate( const QPointF& offset )
{
  _pd->m_offset = offset;
}
