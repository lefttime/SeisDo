#ifndef SHARED_HPP
#define SHARED_HPP

#include <QVector>
#include <QVector2D>

struct SliceConfig {
  QVector<qint32> _indexes;
  QVector2D       _timeRange;
  qint32          _timeInterval;
  qint32          _traceCount;

  bool operator == ( const SliceConfig& config ) {
    if( config._indexes == this->_indexes &&
        config._timeRange == this->_timeRange &&
        config._timeInterval == this->_timeInterval &&
        config._traceCount == this->_traceCount ) {
      return true;
    } else {
      return false;
    }
  }

  bool operator != ( const SliceConfig& config ) {
    return !(*this == config);
  }
};

#endif // SHARED_HPP
