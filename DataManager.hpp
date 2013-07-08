#ifndef DATAMANAGER_HPP
#define DATAMANAGER_HPP

#include <QObject>

#include "UniformData2D.hpp"

class DataManager : public QObject
{
  Q_OBJECT;

public:

  DataManager( QObject* parent=0 );
  ~DataManager();

  UniformData2D prepareData( int id=0 ) const;

private:

  class DataManagerPrivate;
  QScopedPointer<DataManagerPrivate>         _pd;

};

#endif // DATAMANAGER_HPP
