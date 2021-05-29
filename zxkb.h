#include <QWidget>
#include <QLabel>
#include <QPainter>
#include <QPaintEvent>
#include <windows.h>
#include <winuser.h>
#include "globalbits.h"
#include <QDebug>

UINT sendkeypress(UINT key, int keyup) {
    INPUT inputs[1] = {};
    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = key;
    if(keyup == KEYEVENTF_KEYUP) inputs[0].ki.dwFlags = KEYEVENTF_KEYUP;
    UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
    return uSent;
}

class ZXKB : public QWidget {
    Q_OBJECT

public:
    ZXKB(QWidget *parent = 0);
    ~ZXKB() {};
    TZXKeys FKeys[40];
private:    
    void DrawNumberKey(QPainter *p, int l, int i);
    void DrawStandardKey(QPainter *p, int l, int i, int t);
    void DrawSpecialKey(QPainter *p, TZXKeyType ty, int l, int i, int t);
    //QLabel *test;

protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void MouseDown(QMouseEvent *event);
    void MouseUp(QMouseEvent *event);

};
