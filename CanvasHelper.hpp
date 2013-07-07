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

  void processMouseDoubleClick( QMouseEvent* event );
  void processMouseMove( QMouseEvent* event );
  void processMousePress( QMouseEvent* event );
  void processMouseRelease( QMouseEvent* event );

private:

  class CanvasHelperPrivate;
  QScopedPointer<CanvasHelperPrivate>         _pd;

};

#endif // CANVASHELPER_HPP
