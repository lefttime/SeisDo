#include "Canvas.hpp"

#include "CanvasHelper.hpp"
#include "LinearScaleEngine.hpp"

#include <qwt_plot_grid.h>
#include <qwt_plot_canvas.h>
#include <qwt_scale_widget.h>

class Canvas::CanvasPrivate
{
public:

  CanvasPrivate( Canvas* me ) : m_self( me ) {
  }

  ~CanvasPrivate() {
    delete m_helper;
  }

  void init() {
    initAxes();
    initGrid();

    m_self->setCanvasBackground( Qt::white );

    QwtPlotCanvas* canvas = dynamic_cast<QwtPlotCanvas*>( m_self->canvas() );
    canvas->setFrameShape( QFrame::StyledPanel );
    canvas->setBorderRadius( 5 );

    m_helper = new CanvasHelper( m_self );
  }

  void initAxes() {
    m_self->enableAxis( QwtPlot::xTop);
    m_self->enableAxis( QwtPlot::yRight );
    m_self->enableAxis( QwtPlot::xBottom, false );
    m_self->axisWidget( QwtPlot::xTop )->setMargin( 0 );
    m_self->axisWidget( QwtPlot::yLeft )->setMargin( 0 );
    m_self->axisWidget( QwtPlot::yRight )->setMargin( 0 );

    m_self->axisWidget( QwtPlot::xTop )->setTitle( tr( "PaoNo" ) );
    m_self->axisWidget( QwtPlot::yRight )->setColorBarEnabled( true );
    m_self->axisWidget( QwtPlot::yLeft )->setTitle( tr( "Time[ms]" ) );

    LinearScaleEngine* scaleEngine = new LinearScaleEngine();
    m_self->setAxisScaleEngine( QwtPlot::xTop, scaleEngine );
  }

  void initGrid() {
    QwtPlotGrid* plotGrid = new QwtPlotGrid();
    plotGrid->enableX( false );
    plotGrid->attach( m_self );
  }

  Canvas*         m_self;
  CanvasHelper*   m_helper;
};

Canvas::Canvas( QWidget* parent ) : QwtPlot( parent ), _pd( new CanvasPrivate( this ) )
{
  _pd->init();
}

Canvas::~Canvas()
{
}
