#include "Canvas.hpp"
#include "Scene.hpp"

class Canvas::CanvasPrivate
{
public:

  CanvasPrivate( Canvas* me ) : m_self( me ) {
  }

  Canvas*         m_self;
};

Canvas::Canvas( QWidget* parent ) : QGraphicsView( parent ), _pd( new CanvasPrivate( this ) )
{
  setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
  setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
}

Canvas::~Canvas()
{
}

void Canvas::resizeEvent( QResizeEvent* event )
{
  Q_UNUSED( event );
  Scene* scenePtr = dynamic_cast<Scene*>( scene() );
  if( scenePtr ) {
    fitInView( scenePtr->plotConfig()._plotArea );
    emit plotAreaChanged( scenePtr->plotConfig()._plotArea );
  }
}

