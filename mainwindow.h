#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QTouchDevice>
#include <QEvent>
#include <QTouchEvent>
#include <QList>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#ifdef Q_OS_WIN
#include <windows.h>
#include <winuser.h>
#endif
#ifdef Q_OS_LINUX
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/uinput.h>
#define UINT uint
#endif
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
    QSystemTrayIcon *trayIcon;
    QMenu *trayMenu;
    QAction *menuRestore;
    QAction *menuExit;
    bool HasTouch;
    int fd;

protected:
    virtual bool event(QEvent *event);

private slots:
    void KeyDown(UINT key);
    void KeyUp(UINT key);
    void trayIconActivated(QSystemTrayIcon::ActivationReason reason);
    void menuRestoreClick();
    void menuExitClick();
};
#endif // MAINWINDOW_H
