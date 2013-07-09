#include "Scene.hpp"

class Scene::ScenePrivate
{
public:

  ScenePrivate( Scene* me ) : m_self( me ) {
  }

  ~ScenePrivate() {
  }

  Scene*         m_self;
};

Scene::Scene( QObject* parent ) : QObject( parent ), _pd( new ScenePrivate( this ) )
{
}

Scene::~Scene()
{
}
