#include "mainwindow.h"
#include "ui_mainwindow.h"

UINT sendkeypress(UINT key, int keyup) {
    INPUT inputs[1] = {};
    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = key;
    if(keyup == KEYEVENTF_KEYUP) inputs[0].ki.dwFlags = KEYEVENTF_KEYUP;
    UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
    return uSent;
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::Dialog);
    this->setAttribute(Qt::WA_AcceptTouchEvents);
    SetWindowLongPtr((HWND)QWidget::winId(), GWL_EXSTYLE, WS_EX_NOACTIVATE);

    kb = new ZXKB(this);
    this->setCentralWidget(kb);
    this->setWindowTitle("ZX Spectrum Virtual Keyboard");
}

MainWindow::~MainWindow() {
    delete ui;
}

bool MainWindow::event(QEvent *event) {
    switch(event->type()) {
        case QEvent::TouchBegin:
        case QEvent::TouchEnd:
        case QEvent::TouchUpdate: {
            QTouchEvent *touchEvent = static_cast<QTouchEvent*>(event);
            QList<QTouchEvent::TouchPoint> touchPoints = touchEvent->touchPoints();
            foreach(const QTouchEvent::TouchPoint& touchPoint, touchPoints) {
                switch (touchPoint.state()) {
                case Qt::TouchPointReleased: {
                    for(int i=0;i<40;i++) {
                        if(kb->FKeys[i].ClickRect.contains(touchPoint.pos().toPoint())) {
                            qDebug() << "Key up! " << kb->FKeys[i].KeyChar << touchPoint.pos();
                            sendkeypress(kb->FKeys[i].KeyCode,KEYEVENTF_KEYUP);
                        }
                    }
                    break;
                }
                case Qt::TouchPointPressed: {
                        for(int i=0;i<40;i++) {
                            if(kb->FKeys[i].ClickRect.contains(touchPoint.pos().toPoint())) {
                                qDebug() << "Key down! " << kb->FKeys[i].KeyChar << touchPoint.pos();
                                sendkeypress(kb->FKeys[i].KeyCode,0);
                            }
                        }
                        break;
                    }
                case Qt::TouchPointMoved: {
                        break;
                    }
                default:
                    break;
                }
            }
            break;
        }
        default:
            return event;
    }
    event->accept();
    return true;
}

