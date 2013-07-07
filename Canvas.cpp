#include "Canvas.hpp"
#include "Scene.hpp"

#include <QResizeEvent>

class Canvas::CanvasPrivate
{
public:

  CanvasPrivate( Canvas* me ) : m_self( me ) {
  }

  Canvas*         m_self;
  Scene*          m_scene;
};

Canvas::Canvas( QWidget* parent ) : QFrame( parent ), _pd( new CanvasPrivate( this ) )
{
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

void Canvas::paintEvent( QPaintEvent* )
{

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

