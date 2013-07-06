#include "Canvas.hpp"
#include "Scene.hpp"

#include <QResizeEvent>

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

  //
  this->setContentsMargins(0, 0, 0, 0);
  this->setOptimizationFlag(QGraphicsView::DontAdjustForAntialiasing);
}

Canvas::~Canvas()
{
}

void Canvas::resizeEvent( QResizeEvent* event )
{
  Q_UNUSED( event );
  Scene* scenePtr = dynamic_cast<Scene*>( scene() );
  if( scenePtr ) {
    float wScale = (rect().width()-2) / scenePtr->plotConfig()._plotArea.width();
    float hScale = (rect().height()-2) / scenePtr->plotConfig()._plotArea.height();
    scale( wScale, hScale );

    emit plotAreaChanged( scenePtr->plotConfig()._plotArea );
  }
}

