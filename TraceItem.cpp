#include "TraceItem.hpp"

#include <qwt_clipper.h>
#include <qwt_painter.h>
#include <qwt_scale_map.h>

class TraceItem::TraceItemPrivate
{
public:

  TraceItemPrivate( TraceItem* me ) : m_self( me ) {
  }

  void closePolyline( QPainter *painter,
                      const QwtScaleMap &xMap, const QwtScaleMap &yMap,
                      QPolygonF &polygon ) const {
    if( polygon.size() < 2 ) {
      return;
    }

    const bool doAlign = QwtPainter::roundingAlignment( painter );

    double baseline = m_self->baseline();

    if( m_self->orientation() != Qt::Vertical ) {
      if( yMap.transformation() ) {
        baseline = yMap.transformation()->bounded( baseline );
      }

      double refY = yMap.transform( baseline );
      if( doAlign ) {
        refY = qRound( refY );
      }

      polygon += QPointF( polygon.last().x(),  refY );
      polygon += QPointF( polygon.first().x(), refY );
    } else {
      if( xMap.transformation() ) {
        baseline = xMap.transformation()->bounded( baseline );
      }

      double refX = xMap.transform( baseline );
      if( doAlign ) {
        refX = qRound( refX );
      }

      polygon += QPointF( refX, polygon.last().y() );
      polygon += QPointF( refX, polygon.first().y() );
    }
  }

  void fillCurve( QPainter* painter,
                  const QwtScaleMap& xMap, const QwtScaleMap& yMap,
                  const QRectF& canvasRect, QPolygonF& polygon ) const {
    if( m_self->brush().style() == Qt::NoBrush ) {
      return;
    }

    closePolyline( painter, xMap, yMap, polygon );
    if( polygon.count() <= 2 ) { // a line can't be filled
      return;
    }

    QBrush theBrush = m_self->brush();
    if( !theBrush.color().isValid() ) {
      theBrush.setColor( m_self->pen().color() );
    }

    if( PaintAttributes() & QwtPlotCurve::ClipPolygons ) {
      polygon = QwtClipper::clipPolygonF( canvasRect, polygon, true );
    }

    painter->save();

    painter->setPen( Qt::NoPen );
    painter->setBrush( theBrush );

    QwtPainter::drawPolygon( painter, polygon );

    painter->restore();

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
//  _pd->fillCurve( painter, xMap, yMap, canvasRect, polygon );

  painter->restore();
}
