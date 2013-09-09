#include "DataManager.hpp"

#include "Shared.hpp"
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

    m_config._timeRange = QVector2D(0, 2000);
    m_config._indexes.resize( 200 );
    for( int idx = 0; idx < m_config._indexes.count(); ++idx ) {
      m_config._indexes[idx] = idx;
    }

    return true;
  }

  void rebuildIndex() {
    m_sampleRate = SeisUtil::swap_int16( SeisUtil::readInt16At( m_fileHandle, 3216 ) );
    m_traceLength= SeisUtil::swap_int16( SeisUtil::readInt16At( m_fileHandle, 3220 ) );
    m_formatCode = SeisUtil::swap_int16( SeisUtil::readInt16At( m_fileHandle, 3224 ) );
    m_bytesPerTrace = 240 + m_traceLength*4;
    m_totalTraces = (m_fileHandle->size() - 3200 - 400) / m_bytesPerTrace;

    qDebug() << "totalTraces: " << m_totalTraces;
  }

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

  SectionConfig        m_config;
};

DataManager::DataManager( const QString& fileName, QObject* parent )
  : QObject( parent ), _pd( new DataManagerPrivate( this, fileName ) )
{
  _pd->init();
}

DataManager::~DataManager()
{
}

qint32 DataManager::totalTraces() const
{
  return _pd->m_totalTraces;
}

const QVector<qint32>&DataManager::indexes() const
{
  return _pd->m_config._indexes;
}

void DataManager::setIndexes( const QVector<qint32>& indexes )
{
  if( _pd->m_config._indexes != indexes ) {
    _pd->m_config._indexes = indexes;
    emit dataChanged();
  }
}

const QVector2D& DataManager::timeRange() const
{
  return _pd->m_config._timeRange;
}

void DataManager::setTimeRange( const QVector2D& timeRange )
{
  if( _pd->m_config._timeRange != timeRange ) {
    _pd->m_config._timeRange = timeRange;
    emit dataChanged();
  }

}

qint32 DataManager::traceCount() const
{
  return _pd->m_config._traceCount;
}

void DataManager::setTraceCount( qint32 traceCount )
{
  if( _pd->m_config._traceCount != traceCount ) {
    _pd->m_config._traceCount = traceCount;
    emit dataChanged();
  }
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
