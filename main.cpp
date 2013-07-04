#include <QtGui/QApplication>

#include "SeisDo.hpp"

int main( int argc, char* argv[] )
{
  QApplication app( argc, argv );

  SeisDo w;
  w.show();

  return app.exec();
}
