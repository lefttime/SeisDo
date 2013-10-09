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

  const QVector2D& dataRange() const;
  void setDataRange( const QVector2D& dataRange );

  const QVector<qint32>& indexes() const;
  void setIndexes( const QVector<qint32>& indexes );

  const QVector2D& timeRange() const;
  void setTimeRange( const QVector2D& timeRange );

  const QVector<qreal>& data() const;
  void setData( const QVector<qreal>& data );

  Q_DISABLE_COPY( UniformData2D );

private:

  class UniformData2DPrivate;
  QScopedPointer<UniformData2DPrivate>         _pd;
};

#endif // UNIFORMDATA2D_HPP
