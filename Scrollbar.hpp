#ifndef SCROLLBAR_H
#define SCROLLBAR_H

#include <QScrollbar>

class ScrollBar: public QScrollBar
{
  Q_OBJECT;

public:

  ScrollBar( QWidget* parent=0 );
  ScrollBar( Qt::Orientation, QWidget* parent=0 );
  ScrollBar( double minBase, double maxBase,
             Qt::Orientation orientation, QWidget* parent=0 );

  void setInverted( bool );
  bool isInverted() const;

  double minBaseValue() const;
  double maxBaseValue() const;

  double minSliderValue() const;
  double maxSliderValue() const;

  int extent() const;

Q_SIGNALS:

  void sliderMoved( Qt::Orientation, double, double );
  void valueChanged( Qt::Orientation, double, double );

public Q_SLOTS:

  virtual void setBase( double min, double max );
  virtual void moveSlider( double min, double max );

protected:

  void sliderRange( int value, double& min, double& max ) const;
  int mapToTick( double ) const;
  double mapFromTick( int ) const;

private Q_SLOTS:

  void catchValueChanged( int value );
  void catchSliderMoved( int value );

private:

  void init();

  bool    d_inverted;
  double  d_minBase;
  double  d_maxBase;
  int     d_baseTicks;

};

#endif
