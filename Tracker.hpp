#ifndef TRACKER_HPP
#define TRACKER_HPP

#include <qwt_plot_picker.h>

class Tracker : public QwtPlotPicker
{
public:

  Tracker( int xAxis, int yAxis, RubberBand rubberBand, DisplayMode trackerMode, QWidget* canvas );
};

#endif // TRACKER_HPP
