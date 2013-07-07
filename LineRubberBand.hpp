#ifndef LINERUBBERBAND_HPP
#define LINERUBBERBAND_HPP

#include "AbstractShapeItem.hpp"

class LineRubberBand : public AbstractShapeItem
{
public:

  LineRubberBand( const PlotConfig& plotConfig );
  ~LineRubberBand();

  void setFirstPoint( const QPoint& );
  void setSecondPoint( const QPoint& );

protected:

  virtual void doPaint( QPainter* painter );

private:

  class LineRubberBandPrivate;
  QScopedPointer<LineRubberBandPrivate>         _pd;

};

#endif // LINERUBBERBAND_HPP
