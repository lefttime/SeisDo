#include "Canvas.hpp"
#include "Scene.hpp"
#include "CanvasHelper.hpp"

#include <QPalette>
#include <QPainter>
#include <QResizeEvent>

class Canvas::CanvasPrivate
{
public:

  CanvasPrivate( Canvas* me ) : m_self( me ), m_scene( 0 ) {
  }

  ~CanvasPrivate() {
    delete m_helper;
  }

  void init() {
    m_helper = new CanvasHelper( m_self );
  }

  Canvas*         m_self;
  Scene*          m_scene;
  CanvasHelper*   m_helper;
};

Canvas::Canvas( QWidget* parent ) : QFrame( parent ), _pd( new CanvasPrivate( this ) )
{
  QPalette palette;
  palette.setColor( QPalette::Window, Qt::white );
  setPalette( palette );

  _pd->init();
}

Canvas::~Canvas()
{
}

void Canvas::setScene( Scene* scene )
{
  _pd->m_scene = scene;
}

Scene* Canvas::scene() const
{
  return _pd->m_scene;
}

void Canvas::paintEvent( QPaintEvent* event )
{
  QFrame::paintEvent( event );

  QPainter painter( this );
  _pd->m_scene->render( &painter );
  update();
}

void Canvas::resizeEvent( QResizeEvent* event )
{
  Q_UNUSED( event );
  Scene* scenePtr = scene();
  if( scenePtr ) {
    PlotConfig plotConfig = scenePtr->plotConfig();
    plotConfig._plotArea = rect();
    scenePtr->setPlotConfig( plotConfig );

    emit plotAreaChanged( scenePtr->plotConfig()._plotArea );
  }
}

void Canvas::mouseDoubleClickEvent( QMouseEvent* event )
{
  _pd->m_helper->processMouseDoubleClick( event );
}

void Canvas::mouseMoveEvent( QMouseEvent* event )
{
  _pd->m_helper->processMouseMove( event );
}

void Canvas::mousePressEvent( QMouseEvent* event )
{
  _pd->m_helper->processMousePress( event );
}

void Canvas::mouseReleaseEvent( QMouseEvent* event )
{
  _pd->m_helper->processMouseRelease( event );
}
