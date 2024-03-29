#include <QWidget>
#include <QLabel>
#include <QPainter>
#include <QPaintEvent>
#ifdef Q_OS_WIN
#include <windows.h>
#include <winuser.h>
#endif
#include "globalbits.h"

class ZXKB : public QWidget {
    Q_OBJECT

public:
    ZXKB(QWidget *parent = 0);
    ~ZXKB() {};
    TZXKeys FKeys[40];
private:    
    void DrawNumberKey(QPainter *p, int l, int i);
    void DrawGraphic(QPainter *p, int l, int i);
    void DrawStandardKey(QPainter *p, int l, int i, int t);
    void DrawSpecialKey(QPainter *p, TZXKeyType ty, int l, int i, int t);

protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

signals:
    void KeyDown(UINT key);
    void KeyUp(UINT key);

private slots:

};
