#include "DataManager.hpp"

class DataManager::DataManagerPrivate
{
public:

  DataManagerPrivate( DataManager* me ) : m_self( me ) {
  }

  DataManager*         m_self;
};

DataManager::DataManager( QObject* parent )
  : QObject( parent ), _pd( new DataManagerPrivate( this ) )
{
}

DataManager::~DataManager()
{
}

UniformData2D DataManager::prepareData( int ) const
{
  int rowCount = 0;
  int colCount = 0;
  QVector<float> sampleData( 0 );

  return UniformData2D( sampleData, rowCount, colCount );
}
