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

  void setScene( Scene* );
  Scene* scene() const;

  void enablePicking( bool enabled );

  DataManager* dataManager() const;
  void setDataManager( DataManager* dataManager );

protected:

  virtual void changeEvent( QEvent* event );

signals:

  void dataChanged();
  void infoPicking( const QString& );

private:

  class CanvasPrivate;
  QScopedPointer<CanvasPrivate>         _pd;

  friend class CanvasHelper;
};

#endif // CANVAS_HPP
