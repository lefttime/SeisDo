#ifndef UNIFORMDATA2D_HPP
#define UNIFORMDATA2D_HPP

#include <QVector>
#include <QScopedPointer>

class UniformData2D
{
public:

  UniformData2D();
  UniformData2D( const QVector<double>& data, int rowCount, int columnCount );
  ~UniformData2D();

  int rowCount() const;
  void setRowCount( int );

  int columnCount() const;
  void setColumnCount( int );

  const QVector<double>& data() const;
  void setData( const QVector<double>& data );

private:

  class UniformData2DPrivate;
  QScopedPointer<UniformData2DPrivate>         _pd;
};

#endif // UNIFORMDATA2D_HPP