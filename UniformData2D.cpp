#include "UniformData2D.hpp"

UniformData2D::UniformData2D( const QVector<float>& data, int rowCount, int columnCount )
{
  m_minValue = 0;
  m_maxValue = 0;
  setRowCount( rowCount );
  setColumnCount( columnCount );
  setData( data );
}

UniformData2D::~UniformData2D()
{
}

float UniformData2D::minValue() const
{
  return m_minValue;
}

float UniformData2D::maxValue() const
{
  return m_maxValue;
}

int UniformData2D::rowCount() const
{
  return m_rowCount;
}

void UniformData2D::setRowCount( int rowCount )
{
  m_rowCount = rowCount;
}

int UniformData2D::columnCount() const
{
  return m_columnCount;
}

void UniformData2D::setColumnCount( int columnCount )
{
  m_columnCount = columnCount;
}

const QVector<float>& UniformData2D::data() const
{
  return m_data;
}

void UniformData2D::setData( const QVector<float>& data )
{
  m_data = data;

  if( !m_data.isEmpty() ) {
    QVector<float> temp = data;
    qSort( temp );
    m_minValue = temp.first();
    m_maxValue = temp.last();
  }
}
