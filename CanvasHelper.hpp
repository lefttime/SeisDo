#ifndef CANVASHELPER_HPP
#define CANVASHELPER_HPP

#include <QObject>

class Canvas;

class QMouseEvent;

class CanvasHelper : public QObject
{
  Q_OBJECT;

public:

  CanvasHelper( Canvas* target, QObject* parent=0 );
  ~CanvasHelper();

private:

  class CanvasHelperPrivate;
  QScopedPointer<CanvasHelperPrivate>         _pd;

};

#endif // CANVASHELPER_HPP
