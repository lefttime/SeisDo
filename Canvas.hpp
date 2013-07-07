#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <QFrame>

class Scene;

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

signals:

  void plotAreaChanged( QRectF );

private:

  class CanvasPrivate;
  QScopedPointer<CanvasPrivate>         _pd;
};

#endif // CANVAS_HPP
