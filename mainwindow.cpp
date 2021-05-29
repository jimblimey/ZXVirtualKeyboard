#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::Dialog);
    this->setAttribute(Qt::WA_AcceptTouchEvents);
    SetWindowLongPtr((HWND)QWidget::winId(), GWL_EXSTYLE, WS_EX_NOACTIVATE);

    QList<const QTouchDevice *> devices = QTouchDevice::devices();

    HasTouch = (devices.count() > 0);

    kb = new ZXKB(this);
    this->setCentralWidget(kb);
    this->setWindowTitle("ZX Spectrum Virtual Keyboard");

    if(!HasTouch) {

    }
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
                            //qDebug() << "Key up! " << kb->FKeys[i].KeyChar << touchPoint.pos();
                            sendkeypress(kb->FKeys[i].KeyCode,KEYEVENTF_KEYUP);
                        }
                    }
                    break;
                }
                case Qt::TouchPointPressed: {
                        for(int i=0;i<40;i++) {
                            if(kb->FKeys[i].ClickRect.contains(touchPoint.pos().toPoint())) {
                                //qDebug() << "Key down! " << kb->FKeys[i].KeyChar << touchPoint.pos();
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

