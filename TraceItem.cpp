#include "TraceItem.hpp"

#include <qwt_scale_map.h>

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

void TraceItem::fillCurve( QPainter* painter,
                           const QwtScaleMap& xMap,
                           const QwtScaleMap& yMap,
                           const QRectF& canvasRect,
                           QPolygonF& polygon ) const
{
  if( brush().style() == Qt::NoBrush ) {
    return;
  }

#if 0
  painter->save();
  painter->setClipRect( xMap.transform( baseline() ),
                        0, 100, 1000,
                        Qt::ReplaceClip );

  QwtPlotCurve::fillCurve( painter, xMap, yMap, canvasRect, polygon );

  painter->setClipRect( xMap.transform( baseline() ),
                        0, 100, 1000,
                        Qt::NoClip );
  painter->restore();
#else
  double x = xMap.transform( baseline() );
  if( x >= canvasRect.right() ) {
    return;
  }

  x = qMax( x, canvasRect.left() );

  const QRectF clipRect( x, canvasRect.top(),
                         canvasRect.right() - x,
                         canvasRect.height() );

  painter->save();
  painter->setClipRect( clipRect, Qt::IntersectClip );

  QwtPlotCurve::fillCurve( painter, xMap, yMap, canvasRect, polygon );

  painter->restore();
#endif
}
