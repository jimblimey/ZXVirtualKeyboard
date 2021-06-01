#include "mainwindow.h"
#include "ui_mainwindow.h"

#ifdef Q_OS_WIN
UINT sendkeypress(UINT key, int keyup) {
    INPUT inputs[1] = {};
    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = key;
    if(keyup == KEYEVENTF_KEYUP) inputs[0].ki.dwFlags = KEYEVENTF_KEYUP;
    UINT uSent = SendInput(ARRAYSIZE(inputs), inputs, sizeof(INPUT));
    return uSent;
}
#endif

#ifdef Q_OS_LINUX
void sendkeypress(int fd, int type, int code, int val) {
    struct input_event ie;

    ie.type = type;
    ie.code = code;
    ie.value = val;
    ie.time.tv_sec = 0;
    ie.time.tv_usec = 0;

    write(fd, &ie, sizeof(ie));
}
#endif

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::Dialog | Qt::WindowDoesNotAcceptFocus);
    this->setAttribute(Qt::WA_AcceptTouchEvents);

    kb = new ZXKB(this);
    this->setCentralWidget(kb);

#ifdef Q_OS_LINUX
    // Prepare virtual keyboard
    struct uinput_setup usetup;
    fd = open("/dev/uinput", O_WRONLY | O_NONBLOCK);
    ioctl(fd, UI_SET_EVBIT, EV_KEY);

    for(int i=0;i<40;i++) {
        ioctl(fd, UI_SET_KEYBIT, kb->FKeys[i].KeyCode);
    }

    memset(&usetup, 0, sizeof(usetup));
    usetup.id.bustype = BUS_USB;
    usetup.id.vendor = 0xB00B;
    usetup.id.product = 0xA45E;
    strcpy(usetup.name, "ZXKB");
    ioctl(fd, UI_DEV_SETUP, &usetup);
    ioctl(fd, UI_DEV_CREATE);
#endif
#ifdef Q_OS_WIN
    SetWindowLongPtr((HWND)QWidget::winId(), GWL_EXSTYLE, WS_EX_NOACTIVATE);
#endif
    QList<const QTouchDevice*> devices = QTouchDevice::devices();

    HasTouch = (devices.count() > 0);

    this->setWindowTitle((QString)APPNAME + " " + (QString)APPVER);

    if(!HasTouch) {
        connect(kb,SIGNAL(KeyUp(UINT)),this,SLOT(KeyUp(UINT)));
        connect(kb,SIGNAL(KeyDown(UINT)),this,SLOT(KeyDown(UINT)));
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
                        KeyUp(kb->FKeys[i].KeyCode);
                    }
                }
                break;
            }
            case Qt::TouchPointPressed: {
                for(int i=0;i<40;i++) {
                    if(kb->FKeys[i].ClickRect.contains(touchPoint.pos().toPoint())) {
                        KeyDown(kb->FKeys[i].KeyCode);
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

void MainWindow::KeyDown(UINT key) {
#ifdef Q_OS_WIN
    sendkeypress(key,0);
#endif
#ifdef Q_OS_LINUX
    sendkeypress(fd, EV_KEY, key, 1);
    sendkeypress(fd, EV_SYN, SYN_REPORT, 0);
#endif
}

void MainWindow::KeyUp(UINT key) {
#ifdef Q_OS_WIN
    sendkeypress(key,KEYEVENTF_KEYUP);
#endif
#ifdef Q_OS_LINUX
    sendkeypress(fd, EV_KEY, key, 0);
    sendkeypress(fd, EV_SYN, SYN_REPORT, 0);
#endif
}
