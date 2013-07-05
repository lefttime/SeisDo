#include "Canvas.hpp"

class Canvas::CanvasPrivate
{
public:

  CanvasPrivate( Canvas* me ) : m_self( me ) {
  }

  Canvas*         m_self;
};

Canvas::Canvas( QWidget* parent ) : QGraphicsView( parent ), _pd( new CanvasPrivate( this ) )
{
}

Canvas::~Canvas()
{
}
