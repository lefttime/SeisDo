#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <qwt_plot.h>

class Scene;
class CanvasHelper;

class Canvas : public QwtPlot
{
  Q_OBJECT;

public:

  Canvas( QWidget* parent );
  ~Canvas();

private:

  class CanvasPrivate;
  QScopedPointer<CanvasPrivate>         _pd;

  friend class CanvasHelper;
};

#endif // CANVAS_HPP
