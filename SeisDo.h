#ifndef SEISDO_H
#define SEISDO_H

#include <QtGui/QMainWindow>

class SeisDo : public QMainWindow
{
  Q_OBJECT;

public:

  SeisDo( QWidget* parent=0, Qt::WFlags flags=0 );
  ~SeisDo();

private:

  class SeisDoPrivate;
  QScopedPointer<SeisDoPrivate>         _pd;

};

#endif // SEISDO_H