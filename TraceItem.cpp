#include "TraceItem.hpp"

#include "SeisUtil.hpp"
#include "UniformData2D.hpp"

#include <QPainter>
#include <QPainterPath>

class TraceItem::TraceItemPrivate
{
public:

  TraceItemPrivate( TraceItem* me, const UniformData2D& data )
    : m_self( me ), m_data( data ), m_scale( 2.0f ) {
  }

  void render( QPainter* painter ) {
    painter->save();

    int columnCount = m_data.columnCount();
    QRect plotArea = m_self->plotConfig()._plotArea;

    QRectF srcRect(0, 0, 1024, 1024);
    float stride = srcRect.width() / columnCount;
    QTransform trans = SeisUtil::generateTrans( srcRect, plotArea );
    for( int traceIdx = 0; traceIdx < columnCount; ++traceIdx ) {
      QRectF targetRect( traceIdx*stride, 0, stride, srcRect.height() );
      drawTrace( traceIdx, targetRect, trans, painter );
    }

    painter->restore();
  }

  void drawTrace( int traceIdx, const QRectF& targetRect, const QTransform& trans, QPainter* painter ) {
    int rowCount = m_data.rowCount();
    const QVector<float>& data = m_data.data();

    int offset = traceIdx * rowCount;
    float vDelta = float(targetRect.height()) /  rowCount;

    QVector<QPointF> points;
    QPainterPath painterPath;
    float valueSpan = m_data.maxValue()-m_data.minValue();
    for( int idx = 0; idx < rowCount; ++idx ) {
      float val = data.at( offset + idx ) * m_scale;
      float ratio = (val-m_data.minValue()) / valueSpan;
      float xpos = ratio * targetRect.width() + targetRect.left();
      float ypos = idx * vDelta;
      points << trans.map( QPointF(xpos, ypos) );
    }
    painter->drawPolyline( points.data(), points.count() );
  }

  TraceItem*            m_self;
  const UniformData2D&  m_data;

  float                 m_scale;
};

TraceItem::TraceItem( const PlotConfig& plotConfig, const UniformData2D& data )
  : AbstractShapeItem( plotConfig ), _pd( new TraceItemPrivate( this, data ) )
{
}

TraceItem::~TraceItem()
{
}

float TraceItem::scale() const
{
  return _pd->m_scale;
}

void TraceItem::setScale( float scale )
{
  _pd->m_scale = scale;
}

void TraceItem::doPaint( QPainter* painter )
{
  Q_UNUSED( painter );
  if( _pd->m_data.data().isEmpty() ) {
    return;
  }
  _pd->render( painter );
}
