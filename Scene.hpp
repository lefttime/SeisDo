#ifndef SCENE_HPP
#define SCENE_HPP

#include <QObject>
#include "Shared.hpp"

class Scene : public QObject
{
  Q_OBJECT;

public:

  Scene( QObject* parent=0 );
  ~Scene();

  const PlotConfig& plotConfig() const;
  void setPlotConfig( const PlotConfig& );

private:

  class ScenePrivate;
  QScopedPointer<ScenePrivate>         _pd;
};

#endif // SCENE_HPP
