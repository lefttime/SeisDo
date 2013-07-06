#ifndef LEGEND_HPP
#define LEGEND_HPP

#include <QLabel>

class Legend : public QLabel
{
  Q_OBJECT;

public:

  Legend( QWidget* parent );
  ~Legend();

  const QRectF& plotArea() const;
  void setPlotArea( const QRectF& plotArea );

protected:

public slots:

  void changePlotArea( QRectF plotArea );

private:

  class LegendPrivate;
  QScopedPointer<LegendPrivate>         _pd;
};

#endif // LEGEND_HPP
