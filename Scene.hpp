#ifndef SCENE_HPP
#define SCENE_HPP

#include <QObject>
#include "Shared.hpp"

class QPainter;
class AbstractShapeItem;

class Scene : public QObject
{
  Q_OBJECT;

public:

  Scene( QObject* parent=0 );
  ~Scene();

  void addItem( AbstractShapeItem* item );
  void removeItem( AbstractShapeItem* item );

  void render( QPainter* painter );

  const PlotConfig& plotConfig() const;
  void setPlotConfig( const PlotConfig& );

private:

  class ScenePrivate;
  QScopedPointer<ScenePrivate>         _pd;
};

#endif // SCENE_HPP
