#ifndef SEISDO_H
#define SEISDO_H

#include <QtGui/QMainWindow>
#include "ui_SeisDo.h"

class SeisDo : public QMainWindow
{
    Q_OBJECT

public:
    SeisDo(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~SeisDo();

private:
    Ui::SeisDoClass ui;
};

#endif // SEISDO_H
