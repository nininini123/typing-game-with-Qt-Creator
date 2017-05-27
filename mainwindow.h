#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QTimer>
#include <QMainWindow>
#include <QPixmap>
#include <QRect>
//#include <QPaintEvent>
#include <QtGui>
#include "randChar.h"
#include "letterpic.h"
#include "QPainter"

#define INTERVAL 300

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
   
    letterPic* letterpic[3];
    QTimer * gameTimer;
public:
    // int setSpeed(int a);
    // int setPicWidth(int a);
    // int setPicHeight(int a);
protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    bool isOver, isStopped;
private slots:
    void run();
    void on_actionexit_triggered();
    void initGame();

    void on_actionhelp_triggered();
};

#endif // MAINWINDOW_H
