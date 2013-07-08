#ifndef UNIFORMDATA2D_HPP
#define UNIFORMDATA2D_HPP

#include <QVector>

class UniformData2D
{
public:

  UniformData2D( const QVector<float>& data=QVector<float>(), int rowCount=0, int columnCount=0 );
  ~UniformData2D();

  float minValue() const;
  float maxValue() const;

  int rowCount() const;
  void setRowCount( int );

  int columnCount() const;
  void setColumnCount( int );

  const QVector<float>& data() const;
  void setData( const QVector<float>& data );

private:

  int                    m_rowCount;
  int                    m_columnCount;

  float                 m_minValue;
  float                 m_maxValue;
  QVector<float>        m_data;
};

#endif // UNIFORMDATA2D_HPP