#ifndef CANVASHELPER_HPP
#define CANVASHELPER_HPP

#include <QObject>

class Canvas;

class QPointF;
class QPolygon;

class CanvasHelper : public QObject
{
  Q_OBJECT;

public:

  CanvasHelper( Canvas* target, QObject* parent=0 );
  ~CanvasHelper();

  bool isEditable() const;

public slots:

  void enableEdit( bool );

  void slotDataSourceChanged();
  void slotMove( const QPointF& );
  void slotSelected( const QPolygon& );

private:

  class CanvasHelperPrivate;
  QScopedPointer<CanvasHelperPrivate>         _pd;

};

#endif // CANVASHELPER_HPP
