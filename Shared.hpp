#ifndef SHARED_HPP
#define SHARED_HPP

#include <QRect>

struct PlotConfig {
  QRect _plotArea;
};

struct SectionConfig {
  int _plotTraces;
  int _beginTrace;
  int _endTrace;
  int _startTime;
  int _stopTime;
};

#endif // SHARED_HPP
