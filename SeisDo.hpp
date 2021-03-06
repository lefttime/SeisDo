#ifndef SEISDO_H
#define SEISDO_H

#include <QtGui/QMainWindow>

class Canvas;
class SeisHelper;

class SeisDo : public QMainWindow
{
  Q_OBJECT;

public:

  SeisDo( QWidget* parent=0, Qt::WFlags flags=0 );
  ~SeisDo();

  Canvas* canvas();

protected:

  virtual void changeEvent( QEvent* event );

private slots:

  void on_actionChinese_triggered();
  void on_actionEnglish_triggered();

  void on_actionNext_triggered();
  void on_actionPrevious_triggered();

private:

  class SeisDoPrivate;
  QScopedPointer<SeisDoPrivate>         _pd;

  friend class SeisHelper;
};

#endif // SEISDO_H