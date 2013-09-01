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

  UniformData2D prepareDataWithIndexes( const QVector<qint32>& indexes,
                                        const QVector2D& timeRange );

private:

  class DataManagerPrivate;
  QScopedPointer<DataManagerPrivate>         _pd;

};

#endif // DATAMANAGER_HPP
