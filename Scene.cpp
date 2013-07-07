#include "Scene.hpp"
#include "AbstractShapeItem.hpp"

#include <QPainter>

class Scene::ScenePrivate
{
public:

  ScenePrivate( Scene* me ) : m_self( me ) {
    m_items.clear();
  }

  ~ScenePrivate() {
    qDeleteAll( m_items );
  }

  Scene*                    m_self;
  PlotConfig                m_config;
  QList<AbstractShapeItem*> m_items;
};

Scene::Scene( QObject* parent ) : QObject( parent ), _pd( new ScenePrivate( this ) )
{
}

Scene::~Scene()
{
}

void Scene::addItem( AbstractShapeItem* item )
{
  _pd->m_items.append( item );
}

void Scene::removeItem( AbstractShapeItem* item )
{
  _pd->m_items.removeAll( item );
}

void Scene::render( QPainter* painter )
{
  foreach( AbstractShapeItem* shapeItem, _pd->m_items ) {
    painter->save();
    shapeItem->render( painter );
    painter->restore();
  }
}

const PlotConfig& Scene::plotConfig() const
{
  return _pd->m_config;
}

void Scene::setPlotConfig( const PlotConfig& plotConfig )
{
  _pd->m_config = plotConfig;
}
