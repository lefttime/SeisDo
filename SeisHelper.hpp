#ifndef SEISHELPER_HPP
#define SEISHELPER_HPP

#include <QObject>

class SeisDo;
class SeisHelper : public QObject
{
  Q_OBJECT;

public:

  SeisHelper( SeisDo* target, QObject* parent=0 );
  ~SeisHelper();

private:

  class SeisHelperPrivate;
  QScopedPointer<SeisHelperPrivate>         _pd;
};

#endif // SEISHELPER_HPP
