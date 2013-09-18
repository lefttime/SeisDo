#ifndef TRACEITEM_HPP
#define TRACEITEM_HPP

#include <qwt_plot_curve.h>

class TraceItem : public QwtPlotCurve
{
public:

  TraceItem();
  ~TraceItem();

protected:

  virtual void fillCurve( QPainter* painter,
                          const QwtScaleMap& xMap,
                          const QwtScaleMap& yMap,
                          const QRectF& canvasRect,
                          QPolygonF& polygon ) const;

private:

  class TraceItemPrivate;
  QScopedPointer<TraceItemPrivate>         _pd;
};

#endif // TRACEITEM_HPP
