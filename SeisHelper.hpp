#ifndef SEISHELPER_HPP
#define SEISHELPER_HPP

#include <QObject>

class SeisDo;
struct SectionConfig;

class SeisHelper : public QObject
{
  Q_OBJECT;

public:

  SeisHelper( SeisDo* target, QObject* parent=0 );
  ~SeisHelper();

  const SectionConfig& sectionConfig() const;
  void setSectionConfig( const SectionConfig& );

  bool open();
  void save();
  void saveAs();
  void load();
  void close();

  void next();
  void previous();
  void sectionEdit();

private:

  class SeisHelperPrivate;
  QScopedPointer<SeisHelperPrivate>         _pd;
};

#endif // SEISHELPER_HPP
