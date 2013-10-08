#include "TraceItem.hpp"

#include <qwt_clipper.h>
#include <qwt_painter.h>
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
  setOrientation( Qt::Horizontal );
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

  qreal x = xMap.transform( baseline() );
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
}
