#include "CanvasHelper.hpp"

#include "Canvas.hpp"
#include "Picker.hpp"
#include "Shared.hpp"
#include "Tracker.hpp"
#include "SliceItem.hpp"
#include "DataManager.hpp"

#include <QLineF>
#include <qwt_symbol.h>
#include <qwt_plot_curve.h>

class CanvasHelper::CanvasHelperPrivate
{
public:

  CanvasHelperPrivate( CanvasHelper* me, Canvas* target )
    : m_self ( me ), m_target( target ), m_slice( 0 ), m_firstArrival( 0 ) {
    m_curveList.clear();
    m_target->setAutoReplot( false );
  }

  ~CanvasHelperPrivate() {
    if( m_firstArrival ) {
      delete m_firstArrival;
    }

    if( m_slice ) {
      delete m_slice;
    }
  }

  void init() {
    m_slice = new SliceItem( m_target->dataManager(), SliceConfig() );
    m_slice->attach( m_target );

    m_firstArrival = new QwtPlotCurve( "FristArrival" );
    m_firstArrival->attach( m_target );
    m_firstArrival->setStyle( QwtPlotCurve::NoCurve );
    m_firstArrival->setSymbol( new QwtSymbol( QwtSymbol::XCross,
                                              Qt::NoBrush,
                                              QPen( Qt::red ),
                                              QSize( 5, 5 ) ) );

    m_tracker = new Tracker( QwtPlot::xBottom, QwtPlot::yLeft,
                             QwtPicker::CrossRubberBand,
                             QwtPicker::AlwaysOff, m_target->canvas() );

    m_picker = new Picker( QwtPlot::xBottom, QwtPlot::yLeft,
                           QwtPicker::CrossRubberBand,
                           QwtPicker::AlwaysOff, m_target->canvas() );
    m_picker->setEnabled( false );

    QObject::connect( m_tracker, SIGNAL( moved( const QPointF& ) ),
                      m_self, SLOT( slotMove( const QPointF& ) ) );
    QObject::connect( m_picker, SIGNAL( selected( const QPolygon& ) ),
                      m_self, SLOT( slotSelected(const QPolygon& ) ) );
  }

  void update() {
    DataManager* dataManager = m_target->dataManager();
    if( !dataManager ) {
      clear();
      return;
    }

    const SliceConfig& config = dataManager->sliceConfig();
    m_markers.resize( config._traceCount );
    for( int idx = 0; idx < config._traceCount; ++idx ) {
      qreal ypos = qBound( config._timeRange.x(),
                           m_markers.at( idx ).y(),
                           config._timeRange.y() );
      m_markers[idx].setX( config._indexes.at( idx ) );
      m_markers[idx].setY( ypos );
    }

    updateAxes();
    updateSlice();
    updateFirstArrival();
    m_target->replot();
  }

  void clear() {
    qDeleteAll( m_curveList );
    m_curveList.clear();

    m_markers.clear();
    m_slice->clear();
    m_firstArrival->setSamples( m_markers );

    m_target->replot();
  }

  void updateSlice() {
    const SliceConfig& config = m_target->dataManager()->sliceConfig();
    m_slice->setConfig( config );
    m_slice->update();
  }

  void updateAxes() {
    const SliceConfig& config = m_target->dataManager()->sliceConfig();
    const QVector2D& timeRange = config._timeRange;
    int xStart = config._indexes.first() + 1;
    int xStop  = config._indexes.first() + config._traceCount;
    int xStep  = 10;
    int yStart = timeRange.x();
    int yStop  = timeRange.y();
    int yStep  = (timeRange.y()-timeRange.x())/10;
    m_target->setAxisScale( QwtPlot::xTop,    xStart, xStop,  xStep );
    m_target->setAxisScale( QwtPlot::xBottom, xStart, xStop,  xStep );
    m_target->setAxisScale( QwtPlot::yLeft,   yStop,  yStart, yStep );
    m_target->setAxisScale( QwtPlot::yRight,  yStop,  yStart, yStep );
  }

  void updateFirstArrival() {
    m_firstArrival->setSamples( m_markers );
  }

  CanvasHelper*         m_self;
  Canvas*               m_target;

  Picker*               m_picker;
  Tracker*              m_tracker;

  QList<QwtPlotCurve*>  m_curveList;
  SliceItem*            m_slice;
  QwtPlotCurve*         m_firstArrival;

  QPolygonF             m_markers;
};

CanvasHelper::CanvasHelper( Canvas* target, QObject* parent )
  : QObject( parent ), _pd( new CanvasHelperPrivate( this, target ) )
{
  _pd->init();
}

CanvasHelper::~CanvasHelper()
{
}

bool CanvasHelper::isEditable() const
{
  return _pd->m_picker->isEnabled();
}

void CanvasHelper::enableEdit(bool isEditable )
{
  _pd->m_picker->setEnabled( isEditable );
}

void CanvasHelper::slotDataSourceChanged()
{
  _pd->m_slice->setDataManager( _pd->m_target->dataManager() );
  _pd->update();
}

void CanvasHelper::slotMove( const QPointF& pos )
{
  QString info;
  info += tr( "DaoNo." ) + QString( ": %1  " ).arg( int(pos.x()+0.5) );
  info += tr( "Offset" ) + QString( ": %1  " ).arg( pos.x() );
  info += tr( "Time" ) + QString( ": %1" ).arg( pos.y() );
  emit _pd->m_target->infoPicking( info );
}

void CanvasHelper::slotSelected( const QPolygon& selected )
{
  DataManager* dataManager = _pd->m_target->dataManager();
  if( !dataManager ) {
    return;
  }

  QwtPlot* plot = _pd->m_target;
  const QwtScaleMap xMap = plot->canvasMap( QwtPlot::xTop );
  const QwtScaleMap yMap = plot->canvasMap( QwtPlot::yLeft );

  QLineF baseLine( QwtScaleMap::invTransform( xMap, yMap, selected.first() ),
                   QwtScaleMap::invTransform( xMap, yMap, selected.last() ) );
  const QVector2D& timeRange = dataManager->sliceConfig()._timeRange;
  const QVector<qint32>& indexes = dataManager->sliceConfig()._indexes;

  QPointF intersected;
  for( int idx = 0; idx < dataManager->sliceConfig()._traceCount; ++idx ) {
    QLineF traceLine( QPointF(indexes.at( idx ), timeRange.x()),
                      QPointF(indexes.at( idx ), timeRange.y()));
    if( baseLine.intersect( traceLine, &intersected ) == QLineF::BoundedIntersection ) {
      _pd->m_markers[idx].setY( intersected.y() );
    }
  }
  _pd->updateFirstArrival();
  _pd->m_target->replot();
}
