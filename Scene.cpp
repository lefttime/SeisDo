#include "Scene.hpp"

class Scene::ScenePrivate
{
public:

  ScenePrivate( Scene* me ) : m_self( me ) {
  }

  Scene*         m_self;
  PlotConfig     m_config;
};

Scene::Scene( QObject* parent ) : QObject( parent ), _pd( new ScenePrivate( this ) )
{
}

Scene::~Scene()
{
}

void Scene::render( QPainter* painter )
{
  Q_UNUSED( painter );
}

const PlotConfig& Scene::plotConfig() const
{
  return _pd->m_config;
}

void Scene::setPlotConfig( const PlotConfig& plotConfig )
{
  _pd->m_config = plotConfig;
}
