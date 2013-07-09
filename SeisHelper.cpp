#include "SeisHelper.hpp"

#include "Scene.hpp"
#include "Canvas.hpp"
#include "SeisDo.hpp"
#include "DataManager.hpp"

#include "TraceItem.hpp"
#include "TimeLineItem.hpp"

#include <QStatusBar>
#include <QLabel>

class SeisHelper::SeisHelperPrivate
{
public:

  SeisHelperPrivate( SeisHelper* me, SeisDo* target ) : m_self( me ), m_target( target ) {
  }

  void init() {
  }

  SeisHelper*         m_self;
  SeisDo*             m_target;
  DataManager         m_dataManager;
  UniformData2D       m_data;

};

SeisHelper::SeisHelper( SeisDo* target, QObject* parent )
  : QObject( parent ), _pd( new SeisHelperPrivate( this, target ) )
{
  _pd->init();
}

SeisHelper::~SeisHelper()
{
}

void SeisHelper::next()
{
  _pd->m_data = _pd->m_dataManager.prepareData( 1 );
}

void SeisHelper::previous()
{
  _pd->m_data = _pd->m_dataManager.prepareData( 0 );
}
