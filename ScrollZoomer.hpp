#ifndef _SCROLLZOOMER_H
#define _SCROLLZOOMER_H

#include <qglobal.h>
#include <qwt_plot.h>
#include <qwt_plot_zoomer.h>

class ScrollBar;
class ScrollData;

class ScrollZoomer: public QwtPlotZoomer
{
  Q_OBJECT;

public:

  enum ScrollBarPosition {
    AttachedToScale,
    OppositeToScale
  };

  ScrollZoomer( QWidget* );
  virtual ~ScrollZoomer();

  ScrollBar* horizontalScrollBar() const;
  ScrollBar* verticalScrollBar() const;

  void setHScrollBarMode( Qt::ScrollBarPolicy );
  void setVScrollBarMode( Qt::ScrollBarPolicy );

  Qt::ScrollBarPolicy vScrollBarMode () const;
  Qt::ScrollBarPolicy hScrollBarMode () const;

  void setHScrollBarPosition( ScrollBarPosition );
  void setVScrollBarPosition( ScrollBarPosition );

  ScrollBarPosition hScrollBarPosition() const;
  ScrollBarPosition vScrollBarPosition() const;

  QWidget* cornerWidget() const;
  virtual void setCornerWidget( QWidget* cw );

  virtual bool eventFilter( QObject*, QEvent* );

  virtual void rescale();

protected:

  virtual ScrollBar* scrollBar( Qt::Orientation );
  virtual void updateScrollBars();
  virtual void layoutScrollBars( const QRect& );

private Q_SLOTS:

  void scrollBarMoved( Qt::Orientation orientation, double min, double max );

private:

  bool needScrollBar( Qt::Orientation ) const;
  int oppositeAxis( int ) const;

  QWidget*    d_cornerWidget;

  ScrollData* d_hScrollData;
  ScrollData* d_vScrollData;

  bool d_inZoom;
  bool d_alignCanvasToScales[ QwtPlot::axisCnt ];
};

#endif
