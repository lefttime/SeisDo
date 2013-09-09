#include "CanvasHelper.hpp"

#include "Canvas.hpp"
#include "Picker.hpp"
#include "Tracker.hpp"
#include "DataManager.hpp"

#include <QtDebug>
#include <qwt_plot_curve.h>

class CanvasHelper::CanvasHelperPrivate
{
public:

  CanvasHelperPrivate( CanvasHelper* me, Canvas* target )
    : m_self ( me ), m_target( target ) {
    m_curveList.clear();
  }

  ~CanvasHelperPrivate() {
  }

  void init() {
    m_tracker = new Tracker( QwtPlot::xBottom, QwtPlot::yLeft,
                             QwtPicker::CrossRubberBand,
                             QwtPicker::AlwaysOff, m_target->canvas() );

    m_picker = new Picker( QwtPlot::xBottom, QwtPlot::yLeft,
                           QwtPicker::CrossRubberBand,
                           QwtPicker::AlwaysOff, m_target->canvas() );

    QObject::connect( m_tracker, SIGNAL( moved( const QPointF& ) ),
                      m_self, SLOT( slotMove( const QPointF& ) ) );
  }

  void update() {
    DataManager* dataManager = m_target->dataManager();
    if( !dataManager ) {
      return;
    }

    const QVector2D& timeRange = dataManager->timeRange();
    const QVector<qint32>& indexes = dataManager->indexes();
    drawSection( dataManager->prepareDataWithIndexes( indexes, timeRange ) );
  }

  void drawSection( const UniformData2D& data2D ) {
    DataManager* dataManager = m_target->dataManager();
    foreach( QwtPlotCurve* curve, m_curveList ) {
      curve->detach();
    }
    qDeleteAll( m_curveList );
    m_curveList.clear();

    qreal minValue = data2D.minValue();
    qreal maxValue = data2D.maxValue();
    qreal absScale = qMax( qAbs( minValue ), qAbs( maxValue ) );

    const QVector2D& timeRange = data2D.timeRange();
    const QVector<qint32>& indexes = data2D.indexes();
    int colCount = data2D.indexes().count();
    int rowCount = data2D.data().count() / colCount;
    qreal sampleInterval = (timeRange.y()-timeRange.x())/rowCount;

    int offset = 0;
    for( int idx = 1; idx <= colCount; ++idx ) {
      QPolygonF samples( rowCount );
      for( int idy = 0; idy < rowCount; ++idy ) {
        qreal val = data2D.data().at( offset++ );
        qreal xpos = ((val + absScale)/(2*absScale) - 0.5)*3;
        samples[idy] = QPointF( xpos+idx+indexes.first(), idy*sampleInterval );
      }
      QwtPlotCurve* plotCurve = new QwtPlotCurve();
      plotCurve->setSamples( samples );
      plotCurve->attach( m_target );
      m_curveList << plotCurve;
    }

    int xStart = data2D.indexes().first() + 1;
    int xStop  = data2D.indexes().first() + dataManager->traceCount();
    int xStep  = 10;
    int yStart = timeRange.x();
    int yStop  = timeRange.y();
    int yStep  = (timeRange.y()-timeRange.x())/10;
    m_target->setAxisScale( QwtPlot::xTop,    xStart, xStop,  xStep );
    m_target->setAxisScale( QwtPlot::xBottom, xStart, xStop,  xStep );
    m_target->setAxisScale( QwtPlot::yLeft,   yStop,  yStart, yStep );
    m_target->setAxisScale( QwtPlot::yRight,  yStop,  yStart, yStep );
    m_target->replot();

  }

  CanvasHelper*         m_self;
  Canvas*               m_target;

  Picker*               m_picker;
  Tracker*              m_tracker;

  QList<QwtPlotCurve*>  m_curveList;
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
