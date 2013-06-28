#include "SeisDo.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SeisDo w;
    w.show();
    return a.exec();
}
