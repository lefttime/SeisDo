#include "Picker.hpp"

#include <QPainter>
#include <qwt_picker_machine.h>

Picker::Picker( int xAxis, int yAxis,
                QwtPicker::RubberBand rubberBand,
                QwtPicker::DisplayMode trackerMode,
                QWidget* canvas )
  : QwtPlotPicker( xAxis, yAxis, rubberBand, trackerMode, canvas )
{
  setStateMachine( new QwtPickerDragLineMachine() );
  setRubberBandPen( QPen( Qt::red, 2, Qt::DashLine) );
}

void Picker::drawRubberBand( QPainter* painter ) const
{
  painter->drawPolyline( selection() );
}
