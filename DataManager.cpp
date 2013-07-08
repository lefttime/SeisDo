#include "DataManager.hpp"

#include <QFile>
#include <QTextStream>

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
  QVector<float> sampleData(0);

  QFile hFile( "E:/sample_data.txt" );
  if( hFile.open( QFile::ReadOnly ) ) {
    QTextStream in( &hFile );
    in >> rowCount >> colCount;

    sampleData.resize( rowCount*colCount );
    float* dataBuffer = sampleData.data();
    while( !in.atEnd() ) {
      in >> *dataBuffer++;
    }

    hFile.close();
  }

  return UniformData2D( sampleData, rowCount, colCount );
}
