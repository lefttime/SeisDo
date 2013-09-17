#ifndef SLICEITEM_HPP
#define SLICEITEM_HPP

#include <QScopedPointer>

class QwtPlot;
class DataManager;
struct SliceConfig;

class SliceItem
{
public:

  SliceItem( DataManager* dataManager, const SliceConfig& config );
  ~SliceItem();

  void attach( QwtPlot* plot );
  void detach();

  void clear();
  void update();

  void setDataManager( DataManager* dataManager );

  const SliceConfig& config() const;
  void setConfig( const SliceConfig& config );

private:

  class SliceItemPrivate;
  QScopedPointer<SliceItemPrivate>         _pd;

};

#endif // SLICEITEM_HPP
