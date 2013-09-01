#include "DataManager.hpp"

#include "SeisUtil.hpp"

#include <QFile>
#include <QtDebug>
#include <QVector2D>

class DataManager::DataManagerPrivate
{
public:

  DataManagerPrivate( DataManager* me, const QString& fileName )
    : m_self( me ), m_fileName( fileName ), m_fileHandle( 0 ) {
  }

  ~DataManagerPrivate() {
    if( m_fileHandle ) {
      m_fileHandle->close();
      delete m_fileHandle;
    }
  }

  bool init() {
    m_fileHandle = new QFile( m_fileName, m_self );
    if( !m_fileHandle->open( QFile::ReadOnly ) ) {
      delete m_fileHandle;
      m_fileHandle = 0;
      return false;
    }
    rebuildIndex();
    return true;
  }

  void rebuildIndex() {
    m_sampleRate = SeisUtil::swap_int16( SeisUtil::readInt16At( m_fileHandle, 3216 ) );
    m_traceLength= SeisUtil::swap_int16( SeisUtil::readInt16At( m_fileHandle, 3220 ) );
    m_formatCode = SeisUtil::swap_int16( SeisUtil::readInt16At( m_fileHandle, 3224 ) );
    m_bytesPerTrace = 240 + m_traceLength*4;
    m_totalTraces = (m_fileHandle->size() - 3200 - 400) / m_bytesPerTrace;

    //sampleOutput( 0, 1 );
  }

  //void sampleOutput( qint32 startIdx, qint32 traceCount ) {
  //  for( int idx = 0; idx < traceCount; ++idx ) {
  //    qint32 offset = 3600 + (startIdx+idx)*m_bytesPerTrace;
  //    qint32 paoIdx = SeisUtil::swap_int32( SeisUtil::readInt32At( m_fileHandle, offset + 8 ) );
  //    qint32 daoIdx = SeisUtil::swap_int32( SeisUtil::readInt32At( m_fileHandle, offset + 12) );

  //    offset += 240;
  //    qDebug() << "PaoIdx: " << paoIdx << ", DaoIdx: " << daoIdx;
  //    qDebug() << "=======================================";
  //    QVector<qreal> data = dataAtIndex( startIdx+idx, QVector2D(0,20) );
  //    for( int idy = 0; idy < 10; ++idy ) {
  //      qDebug() << data.at( idy );
  //    }
  //    qDebug() << "";
  //  }
  //}

  QVector<qreal> dataAtIndex( int traceIndex, const QVector2D& timeRange ) {
    int dataSize = (timeRange.y()-timeRange.x())/(m_sampleRate/1000)+1;
    dataSize = qMin( dataSize, int(m_traceLength) );
    QVector<qreal> result( dataSize );
    qint32 offset = 3600 + traceIndex * m_bytesPerTrace + 240;
    for( int idx = 0; idx < dataSize; ++idx ) {
      qint32 val = SeisUtil::readInt32At( m_fileHandle, offset + idx * 4 );
      result[idx] = SeisUtil::ibm2num( SeisUtil::swap_int32( val ) );
    }
    return result;
  }

  DataManager*         m_self;
  QString              m_fileName;
  QFile*               m_fileHandle;

  qint16               m_sampleRate;
  qint16               m_traceLength;
  qint16               m_formatCode;
  qint16               m_bytesPerTrace;
  qint32               m_totalTraces;
};

DataManager::DataManager( const QString& fileName, QObject* parent )
  : QObject( parent ), _pd( new DataManagerPrivate( this, fileName ) )
{
  _pd->init();
}

DataManager::~DataManager()
{
}

UniformData2D DataManager::prepareDataWithIndexes( const QVector<qint32>& indexes,
                                                   const QVector2D& timeRange )
{
  QVector<qreal> data;
  foreach( qint32 traceIndex, indexes ) {
    data << _pd->dataAtIndex( traceIndex, timeRange );
  }
  return UniformData2D( data, indexes, timeRange );
}
