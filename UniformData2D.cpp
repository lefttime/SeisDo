#include "UniformData2D.hpp"

class UniformData2D::UniformData2DPrivate
{
public:

  UniformData2DPrivate( UniformData2D* me ) : m_self( me ) {
    m_rowCount = 0;
    m_columnCount = 0;
    m_data.clear();
  }

  UniformData2D*         m_self;

  int                    m_rowCount;
  int                    m_columnCount;
  QVector<double>        m_data;
};

UniformData2D::UniformData2D() : _pd( new UniformData2DPrivate( this ) )
{
}

UniformData2D::UniformData2D( const QVector<double>& data, int rowCount, int columnCount )
  : _pd( new UniformData2DPrivate( this ) )
{
  setRowCount( rowCount );
  setColumnCount( columnCount );
  setData( data );
}

UniformData2D::~UniformData2D()
{
}

int UniformData2D::rowCount() const
{
  return _pd->m_rowCount;
}

void UniformData2D::setRowCount( int rowCount )
{
  _pd->m_rowCount = rowCount;
}

int UniformData2D::columnCount() const
{
  return _pd->m_columnCount;
}

void UniformData2D::setColumnCount( int columnCount )
{
  _pd->m_columnCount = columnCount;
}

const QVector<double>& UniformData2D::data() const
{
  return _pd->m_data;
}

void UniformData2D::setData( const QVector<double>& data )
{
  _pd->m_data = data;
}
