#ifndef CANVASHELPER_HPP
#define CANVASHELPER_HPP

#include <QObject>

class Canvas;

class QPointF;
class QPolygon;
class QMouseEvent;

class CanvasHelper : public QObject
{
  Q_OBJECT;

public:

  CanvasHelper( Canvas* target, QObject* parent=0 );
  ~CanvasHelper();

  bool isEditable() const;
  void enableEdit( bool );

public slots:

  void slotDataSourceChanged();
  void slotMove( const QPointF& );

private:

  class CanvasHelperPrivate;
  QScopedPointer<CanvasHelperPrivate>         _pd;

};

#endif // CANVASHELPER_HPP
