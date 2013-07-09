#include "CanvasHelper.hpp"
#include "Canvas.hpp"

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
    test();
  }

  void test() {
    int xStart = 1;
    int xStop = 300;
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
};

CanvasHelper::CanvasHelper( Canvas* target, QObject* parent )
  : QObject( parent ), _pd( new CanvasHelperPrivate( this, target ) )
{
  _pd->init();
}

CanvasHelper::~CanvasHelper()
{
}
