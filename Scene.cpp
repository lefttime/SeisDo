#include "Scene.hpp"

#include "Canvas.hpp"

#include <qwt_plot_item.h>

class Scene::ScenePrivate
{
public:

  ScenePrivate( Scene* me ) : m_self( me ) {
    m_itemList.clear();
  }

  ~ScenePrivate() {
    qDeleteAll( m_itemList );
  }

  Scene*              m_self;
  QList<QwtPlotItem*> m_itemList;
};

Scene::Scene( QObject* parent ) : QObject( parent ), _pd( new ScenePrivate( this ) )
{
}

Scene::~Scene()
{
}

void Scene::addItem( QwtPlotItem* item )
{
  item->attach( _canvas );
  if( !_pd->m_itemList.contains( item ) ) {
    _pd->m_itemList << item;
  }
}

void Scene::removeItem( QwtPlotItem* item  )
{
  item->detach();
  if( _pd->m_itemList.contains( item ) ) {
    _pd->m_itemList.removeAll( item );
  }
}

void Scene::updateAll()
{
  if( _canvas ) {
    foreach( QwtPlotItem* item, _pd->m_itemList ) {
      item->attach( _canvas );
    }
  } else {
    foreach( QwtPlotItem* item, _pd->m_itemList ) {
      item->detach();
    }
  }
}
