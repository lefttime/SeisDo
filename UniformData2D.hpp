#ifndef UNIFORMDATA2D_HPP
#define UNIFORMDATA2D_HPP

#include <QVector>
#include <QVector2D>
#include <QScopedPointer>

class UniformData2D
{
public:

  UniformData2D();
  UniformData2D( const QVector<qreal>& data,
                 const QVector<qint32>& indexes,
                 const QVector2D& timeRange );
  ~UniformData2D();

  qreal minValue() const;
  qreal maxValue() const;

  const QVector<qint32>& indexes() const;
  void setIndexes( const QVector<qint32>& indexes );

  const QVector2D& timeRange() const;
  void setTimeRange( const QVector2D& timeRange );

  const QVector<qreal>& data() const;
  void setData( const QVector<qreal>& data );

private:

  class UniformData2DPrivate;
  QScopedPointer<UniformData2DPrivate>         _pd;
};

#endif // UNIFORMDATA2D_HPP
