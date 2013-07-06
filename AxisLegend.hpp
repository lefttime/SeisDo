#ifndef AXISLEGEND_HPP
#define AXISLEGEND_HPP

#include "Legend.hpp"

class AxisLegend : public Legend
{
  Q_OBJECT;

public:

  enum Direction { East, West, South, North };

  explicit AxisLegend( QWidget* parent=0 );
  ~AxisLegend();

  Direction direction() const;
  void setDirection(Direction direction);

protected:

  virtual void paintEvent ( QPaintEvent* );
  
private:

  class AxisLegendPrivate;
  QScopedPointer<AxisLegendPrivate>         _pd;
};

#endif // AXISLEGEND_HPP
