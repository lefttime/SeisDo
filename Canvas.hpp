#ifndef CANVAS_HPP
#define CANVAS_HPP

#include <qwt_plot.h>

class Scene;
class DataManager;
class CanvasHelper;

class Canvas : public QwtPlot
{
  Q_OBJECT;

public:

  Canvas( QWidget* parent );
  ~Canvas();

  DataManager* dataManager() const;
  void setDataManager( DataManager* dataManager );

signals:

  void changeDataSource();
  void infoPicking( const QString& );

private:

  class CanvasPrivate;
  QScopedPointer<CanvasPrivate>         _pd;

  friend class CanvasHelper;
};

#endif // CANVAS_HPP
