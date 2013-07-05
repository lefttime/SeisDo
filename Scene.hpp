#ifndef SCENE_HPP
#define SCENE_HPP

#include <QGraphicsScene>

class Scene : public QGraphicsScene
{
  Q_OBJECT;

public:

  Scene( QObject* parent=0 );
  ~Scene();

private:

  class ScenePrivate;
  QScopedPointer<ScenePrivate>         _pd;
};

#endif // SCENE_HPP