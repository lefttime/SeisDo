#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <QFrame>

class Scene;
class CanvasHelper;

class Canvas : public QFrame
{
  Q_OBJECT;

public:

  Canvas( QWidget* parent );
  ~Canvas();

  void setScene( Scene* scene );
  Scene* scene() const;

protected:

  virtual void paintEvent( QPaintEvent* );
  virtual void resizeEvent( QResizeEvent* event );

  virtual void mousefloatClickEvent( QMouseEvent* event );
  virtual void mouseMoveEvent( QMouseEvent* event );
  virtual void mousePressEvent( QMouseEvent* event );
  virtual void mouseReleaseEvent( QMouseEvent* event );

signals:

  void plotAreaChanged( QRectF );
  void showPickingInfo( const QString& info, int timeout=0 );

private:

  class CanvasPrivate;
  QScopedPointer<CanvasPrivate>         _pd;

  friend class CanvasHelper;
};

#endif // CANVAS_HPP
