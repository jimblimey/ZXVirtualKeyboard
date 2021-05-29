#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QTouchDevice>
#include <QEvent>
#include <QTouchEvent>
#include <windows.h>
#include <winuser.h>
#include <QDebug>
#include "zxkb.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    ZXKB *kb;

protected:
    virtual bool event(QEvent *event);

//private slots:
    //void TestButtonClicked();
};
#endif // MAINWINDOW_H
