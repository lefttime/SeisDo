#include "CanvasHelper.hpp"
#include "Canvas.hpp"
#include "Scene.hpp"

#include "LineRubberBand.hpp"

#include <QMouseEvent>

class CanvasHelper::CanvasHelperPrivate
{
public:

  CanvasHelperPrivate( CanvasHelper* me, Canvas* target )
    : m_self ( me ), m_target( target ), m_rubberBand( 0 ) {
  }

  ~CanvasHelperPrivate() {
  }

  void init() {
    m_target->setMouseTracking( true );
  }

  CanvasHelper*         m_self;
  Canvas*               m_target;

  LineRubberBand*       m_rubberBand;
};

CanvasHelper::CanvasHelper( Canvas* target, QObject* parent )
  : QObject( parent ), _pd( new CanvasHelperPrivate( this, target ) )
{
  _pd->init();
}

CanvasHelper::~CanvasHelper()
{
}

void CanvasHelper::processMouseDoubleClick( QMouseEvent* event )
{
  Q_UNUSED( event );
}

void CanvasHelper::processMouseMove( QMouseEvent* event )
{
  if( _pd->m_rubberBand ) {
    _pd->m_rubberBand->setSecondPoint( event->pos() );
  }

  QString info = QString( "Tracking: (%1, %2)").arg( event->pos().x() ).arg( event->pos().y() );
  emit _pd->m_target->showPickingInfo( info, 500 );
}

void CanvasHelper::processMousePress( QMouseEvent* event )
{
  if( !_pd->m_rubberBand ) {
    const PlotConfig& plotConfig = _pd->m_target->scene()->plotConfig();
    _pd->m_rubberBand = new LineRubberBand( plotConfig );
    _pd->m_target->scene()->addItem( _pd->m_rubberBand );
  }

  _pd->m_rubberBand->setFirstPoint( event->pos() );
  _pd->m_rubberBand->show();
}

void CanvasHelper::processMouseRelease( QMouseEvent* event )
{
  if( _pd->m_rubberBand ) {
    _pd->m_rubberBand->hide();
  }

  Q_UNUSED( event );
}
