#ifndef PICKER_HPP
#define PICKER_HPP

#include <qwt_plot_picker.h>
#include <QScopedPointer>

class Picker : public QwtPlotPicker
{
public:

  Picker( int xAxis, int yAxis, RubberBand rubberBand, DisplayMode trackerMode, QWidget* canvas );

private:

  virtual void drawRubberBand( QPainter* painter ) const;
};

#endif // PICKER_HPP
