#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <QGraphicsView>

class Canvas : public QGraphicsView
{
  Q_OBJECT;

public:

  Canvas( QWidget* parent );
  ~Canvas();

private:

  class CanvasPrivate;
  QScopedPointer<CanvasPrivate>         _pd;
};

#endif // CANVAS_HPP