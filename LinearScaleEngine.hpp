#ifndef LINEARSCALEENGINE_HPP
#define LINEARSCALEENGINE_HPP

#include <qwt_scale_engine.h>
#include <QScopedPointer>

class LinearScaleEngine : public QwtLinearScaleEngine
{
public:

  LinearScaleEngine( int base=10 );
  ~LinearScaleEngine();

  bool firstTickEnabled() const;
  void enableFirstTick( bool=true );

  bool lastTickEnabled() const;
  void enableLastTick( bool=true );

protected:

  virtual QwtScaleDiv divideScale( double x1, double x2,
                                   int numMajorSteps, int numMinorSteps,
                                   double stepSize=0.0 ) const;

private:

  class LinearScaleEnginePrivate;
  QScopedPointer<LinearScaleEnginePrivate>         _pd;
};

#endif // LINEARSCALEENGINE_HPP
