#include "UniformData2D.hpp"

#include <float.h>

class UniformData2D::UniformData2DPrivate
{
public:

  UniformData2DPrivate( UniformData2D* me ) : m_self( me ) {
  }

  void prepare() {
    m_minValue = FLT_MAX;
    m_maxValue = FLT_MIN;
    foreach( qreal val, m_data ) {
      m_minValue = qMin( m_minValue, val );
      m_maxValue = qMax( m_maxValue, val );
    }
  }

  UniformData2D*         m_self;

  qreal                  m_minValue;
  qreal                  m_maxValue;

  QVector<qreal>         m_data;
  QVector<qint32>        m_indexes;
  QVector2D              m_timeRange;
};

UniformData2D::UniformData2D() : _pd( new UniformData2DPrivate( this ) )
{
}

UniformData2D::UniformData2D( const QVector<qreal>& data,
                              const QVector<qint32>& indexes,
                              const QVector2D& timeRange )
  : _pd( new UniformData2DPrivate( this ) )
{
  setIndexes( indexes );
  setTimeRange( timeRange );
  setData( data );
}

UniformData2D::~UniformData2D()
{
}

qreal UniformData2D::minValue() const
{
  return _pd->m_minValue;
}

qreal UniformData2D::maxValue() const
{
  return _pd->m_maxValue;
}

const QVector<qint32>&UniformData2D::indexes() const
{
  return _pd->m_indexes;
}

void UniformData2D::setIndexes(const QVector<qint32>& indexes)
{
  _pd->m_indexes = indexes;
}

const QVector2D&UniformData2D::timeRange() const
{
  return _pd->m_timeRange;
}

void UniformData2D::setTimeRange( const QVector2D& timeRange )
{
  _pd->m_timeRange = timeRange;
}

const QVector<qreal>& UniformData2D::data() const
{
  return _pd->m_data;
}

void UniformData2D::setData( const QVector<qreal>& data )
{
  _pd->m_data = data;
  _pd->prepare();
}
