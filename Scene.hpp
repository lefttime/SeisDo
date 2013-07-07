#ifndef SCENE_HPP
#define SCENE_HPP

#include <QObject>
#include "Shared.hpp"

class QPainter;

class Scene : public QObject
{
  Q_OBJECT;

public:

  Scene( QObject* parent=0 );
  ~Scene();

  void render( QPainter* painter );

  const PlotConfig& plotConfig() const;
  void setPlotConfig( const PlotConfig& );

private:

  class ScenePrivate;
  QScopedPointer<ScenePrivate>         _pd;
};

#endif // SCENE_HPP
