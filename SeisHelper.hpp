#ifndef SEISHELPER_HPP
#define SEISHELPER_HPP

#include <QObject>

class SeisDo;
struct SliceConfig;

class SeisHelper : public QObject
{
  Q_OBJECT;

public:

  SeisHelper( SeisDo* target, QObject* parent=0 );
  ~SeisHelper();

  const SliceConfig& sliceConfig() const;

  bool open();
  void save();
  void saveAs();
  void load();
  void close();

  void setPickingEnabled( bool enabled );

  void next();
  void previous();
  void sliceEdit();

public slots:

  void setSliceConfig( const SliceConfig& );

private:

  class SeisHelperPrivate;
  QScopedPointer<SeisHelperPrivate>         _pd;
};

#endif // SEISHELPER_HPP
