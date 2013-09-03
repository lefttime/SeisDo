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

  bool open();
  void save();
  void saveAs();
  void load();
  void close();

  void next();
  void previous();

private:

  class SeisHelperPrivate;
  QScopedPointer<SeisHelperPrivate>         _pd;
};

#endif // SEISHELPER_HPP
