#include "Tracker.hpp"

#include <qwt_picker_machine.h>

Tracker::Tracker( int xAxis, int yAxis,
                  RubberBand rubberBand,
                  DisplayMode trackerMode,
                  QWidget* canvas )
  : QwtPlotPicker( xAxis, yAxis, rubberBand, trackerMode, canvas )
{
  setStateMachine( new QwtPickerTrackerMachine() );
  setRubberBandPen( Qt::NoPen );
  //  setRubberBandPen( QPen( Qt::red, 2, Qt::DashLine) );
}
