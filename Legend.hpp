#ifndef LEGEND_HPP
#define LEGEND_HPP

#include <QLabel>

class Legend : public QLabel
{
  Q_OBJECT;

public:

  Legend( QWidget* parent );
  ~Legend();

private:

  class LegendPrivate;
  QScopedPointer<LegendPrivate>         _pd;
};

#endif // LEGEND_HPP