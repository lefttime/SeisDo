#include "TraceItem.hpp"

class TraceItem::TraceItemPrivate
{
public:

  TraceItemPrivate( TraceItem* me ) : m_self( me ) {
  }

  TraceItem*            m_self;
};

TraceItem::TraceItem() : QwtPlotCurve(), _pd( new TraceItemPrivate( this ) )
{
}

TraceItem::~TraceItem()
{
}
