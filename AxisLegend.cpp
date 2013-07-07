#include "AxisLegend.hpp"

#include <QPainter>
#include <QVector2D>

class AxisLegend::AxisLegendPrivate
{
public:

  struct AxisConfig {
    float _start;
    float _end;
    float _step_major;
    float _step_minus;
    QVector2D _range;

    AxisConfig() : _start( 0 ), _end( 0 ), _step_major( 0 ), _step_minus( 0 ), _range(0, 0) {}
  };

  AxisLegendPrivate( AxisLegend* me ) : m_self ( me ) {
    m_direction = AxisLegend::North;
  }

  void doPaint( QPainter* painter ) {
    if( m_self->plotArea().isNull() ) {
      return;
    }

    refreshConfig();

    switch( m_direction ) {
    case AxisLegend::East:  drawFaceToEast( painter );  break;

    case AxisLegend::West:  drawFaceToWest( painter );  break;

    case AxisLegend::South: drawFaceToSouth( painter ); break;

    case AxisLegend::North: drawFaceToNorth( painter ); break;
    }
  }

  void refreshConfig() {
    switch( m_direction ) {
    case AxisLegend::East:
    case AxisLegend::West: {
      m_config._range = QVector2D( m_self->plotArea().top(), m_self->plotArea().bottom() );
    } break;

    case AxisLegend::South:
    case AxisLegend::North: {
      m_config._range = QVector2D( m_self->plotArea().left(), m_self->plotArea().right() );
    } break;
    }

    int span = 10000000;
    float stride = m_config._range.y() - m_config._range.x();
    while( (stride / span) < 10 ) {
      span /= 10;
    }
    if( (stride / span) > 25 ) {
      span *= 10;
    }
    span = qMax( 1, span );
    m_config._start = int(m_config._range.x()) - int(m_config._range.x()) % span + span;
    m_config._end = int(m_config._range.y()) - int(m_config._range.y()) % span;
    m_config._step_major = span;

  }

  void drawFaceToEast( QPainter* painter ) {
    painter->save();
    {
      QRectF srcRect( QPointF(0, m_config._range.x()),
                      QPointF((m_config._range.y()-m_config._range.x()), m_config._range.y()) );
      QRect targetRect = m_self->rect();
      targetRect.setRight( targetRect.width()*0.5 );
      QTransform trans = generateTrans( srcRect, targetRect );

      int pixelOffset = painter->font().pixelSize()*0.5f;
      QFontMetrics fm( painter->font() );
      for( float pos = m_config._start; pos <= m_config._end; pos += m_config._step_major ) {
        painter->drawLine( trans.map( QPointF(0, pos) ),
                           trans.map( QPointF(srcRect.width()*0.25f, pos) ) );

        QPointF textPos = trans.map( QPointF(srcRect.width()*0.25f, pos) );
        QRect textRect = fm.boundingRect( QString::number( pos ) );
        textPos += QPointF( pixelOffset*0.5f, pixelOffset );
        painter->drawText( textPos, QString::number( pos ) );
      }
    }
    painter->restore();
  }

  void drawFaceToWest( QPainter* painter ) {
    painter->save();
    {
      QRectF srcRect( QPointF(0, m_config._range.x()),
                      QPointF((m_config._range.y()-m_config._range.x()), m_config._range.y()) );
      QRect targetRect = m_self->rect();
      targetRect.setLeft( targetRect.width()*0.5 );
      QTransform trans = generateTrans( srcRect, targetRect );

      int pixelOffset = painter->font().pixelSize()*0.5f;
      QFontMetrics fm( painter->font() );
      for( float pos = m_config._start; pos <= m_config._end; pos += m_config._step_major ) {
        painter->drawLine( trans.map( QPointF(srcRect.width(), pos) ),
                           trans.map( QPointF(srcRect.width()*0.75f, pos) ) );

        QPointF textPos = trans.map( QPointF(srcRect.width()*0.75f, pos) );
        QRect textRect = fm.boundingRect( QString::number( pos ) );
        textPos += QPointF( -(textRect.width()+pixelOffset*0.5f), pixelOffset );
        painter->drawText( textPos, QString::number( pos ) );
      }
    }
    painter->restore();
  }

  void drawFaceToSouth( QPainter* painter ) {
    Q_UNUSED( painter );
  }

  void drawFaceToNorth( QPainter* painter ) {
    QVector<QPointF> pointPairs;
    painter->save();
    {
      QRectF srcRect( QPointF(m_config._range.x(), 0),
                      QPointF(m_config._range.y(), (m_config._range.y()-m_config._range.x())) );
      QRect targetRect = m_self->rect();
      targetRect.setTop( targetRect.height()*0.5 );
      QTransform trans = generateTrans( srcRect, targetRect );

      int pixelOffset = painter->font().pixelSize()*0.25f;
      QFontMetrics fm( painter->font() );
      for( float pos = m_config._start; pos <= m_config._end; pos += m_config._step_major ) {
        pointPairs << trans.map( QPointF(pos, srcRect.height() ) );
        pointPairs << trans.map( QPointF(pos, srcRect.height()*0.75f ) );
        painter->drawLine( trans.map( QPointF(pos, srcRect.height()) ),
                           trans.map( QPointF(pos, srcRect.height()*0.75f) ) );

        QPointF textPos = trans.map( QPointF(pos, srcRect.height()*0.75f) );
        QRect textRect = fm.boundingRect( QString::number( pos ) );
        textPos -= QPointF( textRect.width()*0.5f, pixelOffset );
        painter->drawText( textPos, QString::number( pos ) );
      }
    }
    painter->restore();
  }

  QTransform generateTrans( const QRectF& srcRect, const QRect& targetRect ) {
    QTransform result;
    result.reset();

    float wScale = targetRect.width() / srcRect.width();
    float hScale = targetRect.height() / srcRect.height();
    result *= QTransform::fromTranslate( -srcRect.left(), -srcRect.top() );
    result *= QTransform::fromScale( wScale, hScale );
    result *= QTransform::fromTranslate( targetRect.left(), targetRect.top() );

    return result;
  }

  AxisLegend*           m_self;
  AxisLegend::Direction m_direction;
  AxisConfig            m_config;
};

AxisLegend::AxisLegend( QWidget* parent )
  : Legend( parent ), _pd( new AxisLegendPrivate( this ) )
{
}

AxisLegend::~AxisLegend()
{
}

AxisLegend::Direction AxisLegend::direction() const
{
  return _pd->m_direction;
}

void AxisLegend::setDirection( AxisLegend::Direction direction )
{
  _pd->m_direction = direction;
}

void AxisLegend::paintEvent( QPaintEvent* event )
{
  Legend::paintEvent( event );

  QPainter painter( this );

  QFont font = painter.font();
  font.setFamily( "Verdana" );
  font.setPixelSize( 8 );
  painter.setFont( font );
  _pd->doPaint( &painter );
}
