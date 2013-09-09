#ifndef DATAMANAGER_HPP
#define DATAMANAGER_HPP

#include <QObject>

#include "UniformData2D.hpp"

class DataManager : public QObject
{
  Q_OBJECT;

public:

  DataManager( const QString& fileName, QObject* parent=0 );
  ~DataManager();

  qint32 totalTraces() const;

  const QVector<qint32>& indexes() const;
  void setIndexes( const QVector<qint32>& indexes );

  const QVector2D& timeRange() const;
  void setTimeRange( const QVector2D& timeRange );

  qint32 traceCount() const;
  void setTraceCount( qint32 traceCount );

  UniformData2D prepareDataWithIndexes( const QVector<qint32>& indexes,
                                        const QVector2D& timeRange );

signals:

  void dataChanged();

private:

  class DataManagerPrivate;
  QScopedPointer<DataManagerPrivate>         _pd;

};

#endif // DATAMANAGER_HPP
