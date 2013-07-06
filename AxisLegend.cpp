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

  }

  void doPaint( QPainter* painter ) {
    refreshConfig();

    switch( m_direction ) {
    case AxisLegend::East:  drawFaceToEast( painter );  break;

    case AxisLegend::West:  drawFaceToWest( painter );  break;

    case AxisLegend::South: drawFaceToSouth( painter ); break;

    case AxisLegend::North: drawFaceToNorth( painter ); break;
    }
  }

  void refreshConfig() {
    int viewRange;
    switch( m_direction ) {
    case AxisLegend::East:
    case AxisLegend::West: {
      viewRange = m_self->rect().width();
      m_config._range = QVector2D( m_self->plotArea().left(), m_self->plotArea().right() );
    } break;

    case AxisLegend::South:
    case AxisLegend::North: {
      viewRange = m_self->rect().height();
      m_config._range = QVector2D( m_self->plotArea().top(), m_self->plotArea().bottom() );
    } break;
    }

    int span = 10000000;
    float stride = m_config._range.y() - m_config._range.x();
    while( (stride / span) < 10 ) {
      span /= 10;
    }
    if( (stride / span) > (viewRange * 0.2) ) {
      span *= 10;
    }
    m_config._start = int(m_config._range.x()) - int(m_config._range.x()) % span + span;
    m_config._end = int(m_config._range.y()) - int(m_config._range.y()) % span;
    m_config._step_major = span;

  }

  void drawFaceToEast( QPainter* painter ) {
    Q_UNUSED( painter );
  }

  void drawFaceToWest( QPainter* painter ) {
    Q_UNUSED( painter );
  }

  void drawFaceToSouth( QPainter* painter ) {
    Q_UNUSED( painter );
  }

  void drawFaceToNorth( QPainter* painter ) {
    Q_UNUSED( painter );

    // draw Axis
    painter->save();
    {
      QRectF srcRect( QPointF(m_config._range.x(), 0),
                      QPointF(m_config._range.y(), (m_config._range.y()-m_config._range.x())) );
      QRect targetRect = m_self->rect();
      targetRect.setTop( targetRect.height()*0.5 );

      QTransform trans;
      {
        QTransform matrix;

        matrix.reset();
        QPointF offset = srcRect.topLeft() - targetRect.topLeft();
        matrix.translate( offset.x(), offset.y() );
        trans *= matrix;

        matrix.reset();
        matrix.scale( srcRect.size().width() / targetRect.size().width(),
                      srcRect.size().height() / targetRect.size().height() );
        trans *= matrix;

        matrix.reset();
        offset = -offset;
        matrix.translate( offset.x(), offset.y() );
        trans *= matrix;
      }
      painter->setTransform( trans );

      QVector<QPointF> pointPairs;
      for( float pos = m_config._start; pos <= m_config._end; pos += m_config._step_major ) {
        pointPairs << QPointF(pos, srcRect.height());
        pointPairs << QPointF(pos, srcRect.height()*0.5f);
      }

      painter->drawLines( pointPairs );
    }
    painter->restore();
  }

  AxisLegend*           m_self;
  AxisLegend::Direction m_direction;
  AxisConfig            m_config;
};

AxisLegend::AxisLegend( QWidget* parent )
  : Legend( parent ),
    _pd( new AxisLegendPrivate( this ) )
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
  Q_UNUSED( event );
  QPainter painter( this );
  _pd->doPaint( &painter );
}
