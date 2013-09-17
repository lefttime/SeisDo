#include "SliceItem.hpp"

#include "Shared.hpp"
#include "TraceItem.hpp"
#include "DataManager.hpp"
#include "UniformData2D.hpp"

#include <QtDebug>

class SliceItem::SliceItemPrivate
{
public:

  SliceItemPrivate( SliceItem* me, DataManager* dataManager )
    : m_self( me ), m_dataManager( dataManager ) {
    m_traceList.clear();
  }

  ~SliceItemPrivate() {
    clear();
  }

  void attach( QwtPlot* plot ) {
    m_plot = plot;
    if( !m_plot ) {
      detach();
    } else {
      foreach( TraceItem* trace, m_traceList ) {
        trace->attach( m_plot );
      }
    }
  }

  void detach() {
    m_plot = 0;
    foreach( TraceItem* trace, m_traceList ) {
      trace->detach();
    }
  }

  void update() {
    if( !m_dataManager ) {
      clear();
      return;
    }

    adjustTraceList();
    if( m_traceList.isEmpty() ) {
      return;
    }

    updateComponent();
    updateParameter();
  }

  void clear() {
    detach();
    qDeleteAll( m_traceList );
  }

  void adjustTraceList() {
    while( m_traceList.count() < m_config._traceCount ) {
      TraceItem* traceItem = new TraceItem();
      traceItem->attach( m_plot );
      m_traceList << traceItem;
    }

    while( m_traceList.count() > m_config._traceCount ) {
      if( !m_traceList.isEmpty() ) {
        delete m_traceList.takeLast();
      }
    }
  }

  void updateComponent() {
    UniformData2D data = m_dataManager->prepareDataWithIndexes( m_config._indexes,
                                                                m_config._timeRange,
                                                                m_config._timeInterval );
    qreal minValue = data.minValue();
    qreal maxValue = data.maxValue();
    qreal absScale = qMax( qAbs( minValue ), qAbs( maxValue ) );

    const QVector2D& timeRange = data.timeRange();
    const QVector<qint32>& indexes = data.indexes();
    int colCount = data.indexes().count();
    int rowCount = data.data().count() / colCount;
    qreal sampleInterval = (timeRange.y()-timeRange.x())/(rowCount-1);

    int offset = 0;
    for( int idx = 1; idx <= colCount; ++idx ) {
      QPolygonF samples( rowCount );
      for( int idy = 0; idy < rowCount; ++idy ) {
        qreal val = data.data().at( offset++ );
        qreal xpos = ((val + absScale)/(2*absScale) - 0.5)*3;
        qreal ypos = idy * sampleInterval;
        samples[idy] = QPointF( xpos + idx + indexes.first(), ypos );
      }
      m_traceList.at( idx-1 )->setSamples( samples );
    }
  }

  void updateParameter() {
    foreach( TraceItem* trace, m_traceList ) {
      trace->setPen( Qt::black );
    }
  }

  SliceItem*         m_self;
  DataManager*       m_dataManager;
  SliceConfig        m_config;

  QwtPlot*           m_plot;
  QList<TraceItem*>  m_traceList;
};

SliceItem::SliceItem( DataManager* dataManager, const SliceConfig& config )
  : _pd( new SliceItemPrivate( this, dataManager ) )
{
  setConfig( config );
}

SliceItem::~SliceItem()
{
}

void SliceItem::attach( QwtPlot* plot )
{
  _pd->attach( plot );
}

void SliceItem::detach()
{
  _pd->detach();
}

void SliceItem::clear()
{
  setDataManager( 0 );
  _pd->clear();
}

void SliceItem::update()
{
  _pd->update();
}

void SliceItem::setDataManager( DataManager* dataManager )
{
  _pd->m_dataManager = dataManager;
}

const SliceConfig&SliceItem::config() const
{
  return _pd->m_config;
}

void SliceItem::setConfig( const SliceConfig& config )
{
  _pd->m_config = config;
}
