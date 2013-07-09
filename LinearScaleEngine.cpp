#include "LinearScaleEngine.hpp"

class LinearScaleEngine::LinearScaleEnginePrivate
{
public:

  LinearScaleEnginePrivate( LinearScaleEngine* me ) : m_self( me ) {
    m_enableFirstTick = true;
    m_enableLastTick = true;
  }

  LinearScaleEngine*         m_self;

  bool                       m_enableFirstTick;
  bool                       m_enableLastTick;
};

LinearScaleEngine::LinearScaleEngine( int base )
  : QwtLinearScaleEngine( base ), _pd( new LinearScaleEnginePrivate( this ) )
{
}

LinearScaleEngine::~LinearScaleEngine()
{
}

bool LinearScaleEngine::firstTickEnabled() const
{
  return _pd->m_enableFirstTick;
}

void LinearScaleEngine::enableFirstTick( bool firstTickEnabled )
{
  _pd->m_enableFirstTick = firstTickEnabled;
}

bool LinearScaleEngine::lastTickEnabled() const
{
  return _pd->m_enableLastTick;
}

void LinearScaleEngine::enableLastTick( bool lastTickEnabled )
{
  _pd->m_enableLastTick = lastTickEnabled;
}

QwtScaleDiv LinearScaleEngine::divideScale( double x1, double x2,
                                            int numMajorSteps, int numMinorSteps,
                                            double stepSize ) const
{
  QwtScaleDiv result = QwtLinearScaleEngine::divideScale( x1, x2, numMajorSteps, numMinorSteps, stepSize );

  QList< double > ticks;
  ticks = result.ticks( QwtScaleDiv::MajorTick );

  if( !_pd->m_enableFirstTick ) {
    ticks.removeAll( x1 );
  } else if( !ticks.contains( x1 ) ) {
    ticks.push_front( x1 );
  }

  if( !_pd->m_enableLastTick ) {
    ticks.removeAll( x2 );
  } else if( !ticks.contains( x2 ) ) {
    ticks.push_back( x2 );
  }

  result.setTicks( QwtScaleDiv::MajorTick, ticks );

  return result;
}
