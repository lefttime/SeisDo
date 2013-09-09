#ifndef SHARED_HPP
#define SHARED_HPP

#include <QVector>
#include <QVector2D>

struct SectionConfig {
  QVector<qint32> _indexes;
  QVector2D       _timeRange;
  qint32          _traceCount;
};

#endif // SHARED_HPP
