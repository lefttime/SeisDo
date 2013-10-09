#include "UniformData2D.hpp"

#include <float.h>
#include <QtDebug>

class UniformData2D::UniformData2DPrivate
{
public:

  UniformData2DPrivate( UniformData2D* me ) : m_self( me ) {
  }

  void prepare() {
    m_dataRange = QVector2D( FLT_MAX, FLT_MIN );
    foreach( qreal val, m_data ) {
      m_dataRange.setX( qMin( m_dataRange.x(), val ) );
      m_dataRange.setY( qMax( m_dataRange.y(), val ) );
    }
  }

  UniformData2D*         m_self;

  QVector<qreal>         m_data;
  QVector<qint32>        m_indexes;
  QVector2D              m_timeRange;
  QVector2D              m_dataRange;
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

const QVector2D& UniformData2D::dataRange() const
{
  return _pd->m_dataRange;
}

void UniformData2D::setDataRange( const QVector2D& dataRange )
{
  _pd->m_dataRange = dataRange;
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
//  _pd->prepare();
}
