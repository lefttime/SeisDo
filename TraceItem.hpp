#ifndef TRACEITEM_HPP
#define TRACEITEM_HPP

#include <qwt_plot_curve.h>

class TraceItem : public QwtPlotCurve
{
public:

  TraceItem();
  ~TraceItem();

private:

  class TraceItemPrivate;
  QScopedPointer<TraceItemPrivate>         _pd;
};

#endif // TRACEITEM_HPP
