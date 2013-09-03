#ifndef SCENE_HPP
#define SCENE_HPP

#include <QObject>

class Canvas;
class QwtPlotItem;

class Scene : public QObject
{
  Q_OBJECT;

public:

  Scene( QObject* parent=0 );
  ~Scene();

  void addItem( QwtPlotItem* );
  void removeItem( QwtPlotItem* );

private:

  void updateAll();

private:

  class ScenePrivate;
  QScopedPointer<ScenePrivate>         _pd;

  Canvas* _canvas;
  friend class Canvas;
};

#endif // SCENE_HPP
