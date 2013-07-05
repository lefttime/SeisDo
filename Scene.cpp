#include "Scene.hpp"

class Scene::ScenePrivate
{
public:

  ScenePrivate( Scene* me ) : m_self( me ) {
  }

  Scene*         m_self;
};

Scene::Scene( QObject* parent ) : QGraphicsScene( parent ), _pd( new ScenePrivate( this ) )
{
}

Scene::~Scene()
{
}
