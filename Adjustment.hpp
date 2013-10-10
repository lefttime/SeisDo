#ifndef ADJUSTMENT_HPP
#define ADJUSTMENT_HPP

#include <QWidget>

class Adjustment : public QWidget
{
  Q_OBJECT;
  
public:

  explicit Adjustment( QWidget* parent=0 );
  ~Adjustment();

  int value() const;
  
signals:

  void setValue( int );

private:

  class AdjustmentPrivate;
  QScopedPointer<AdjustmentPrivate>         _pd;
};

#endif // ADJUSTMENT_HPP
