#include "CanvasHelper.hpp"

#include "Canvas.hpp"
#include "Picker.hpp"
#include "Tracker.hpp"

#include <QtDebug>
#include <qwt_plot_curve.h>

class CanvasHelper::CanvasHelperPrivate
{
public:

  CanvasHelperPrivate( CanvasHelper* me, Canvas* target )
    : m_self ( me ), m_target( target ) {
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



    sectionTest();
  }

  void sectionTest() {
    int xStart = 1;
    int xStop = 250;
    int xStep = 10;
    int yStart = 0;
    int yStop = 2000;
    int yStep = 200;
    for( int idx = xStart; idx <= xStop; ++idx ) {
      QPolygonF samples;
      for( int idy = yStart; idy < yStop; ++idy ) {
        samples << QPointF( idx, idy );
      }
      QwtPlotCurve* plotCurve = new QwtPlotCurve();
      plotCurve->setSamples( samples );
      plotCurve->attach( m_target );
    }

    m_target->setAxisScale( QwtPlot::xTop, xStart, xStop, xStep );
    m_target->setAxisScale( QwtPlot::xBottom, xStart, xStop, xStep );
    m_target->setAxisScale( QwtPlot::yLeft, yStop, yStart, yStep );
    m_target->setAxisScale( QwtPlot::yRight, yStop, yStart, yStep );
  }

  CanvasHelper*         m_self;
  Canvas*               m_target;

  Picker*               m_picker;
  Tracker*              m_tracker;
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

void CanvasHelper::slotMove( const QPointF& pos )
{
  QString info;
  info += tr( "DaoNo." ) + QString( ": %1  " ).arg( int(pos.x()+0.5) );
  info += tr( "Offset" ) + QString( ": %1  " ).arg( pos.x() );
  info += tr( "Time" ) + QString( ": %1" ).arg( pos.y() );
  emit _pd->m_target->infoPicking( info );
}
