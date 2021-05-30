#include "zxkb.h"

ZXKB::ZXKB( QWidget *parent ): QWidget( parent ) {

  FKeys[0].KeyType=zxkNum;
  FKeys[0].KeyChar="1";
  FKeys[0].TopKeyword="EDIT";
  FKeys[0].TopKeyword2="BLUE";
  FKeys[0].Symbol = "!";
  FKeys[0].BottomKeyword="DEF FN";
  FKeys[0].KeyCode=VK_1;

  FKeys[1].KeyType=zxkNum;
  FKeys[1].KeyChar="2";
  FKeys[1].TopKeyword="CAPS LOCK";
  FKeys[1].TopKeyword2="RED";
  FKeys[1].Symbol = "@";
  FKeys[1].BottomKeyword="FN";
  FKeys[1].KeyCode=VK_2;

  FKeys[2].KeyType=zxkNum;
  FKeys[2].KeyChar="3";
  FKeys[2].TopKeyword="TRUE VIDEO";
  FKeys[2].TopKeyword2="MAGENTA";
  FKeys[2].Symbol = "#";
  FKeys[2].BottomKeyword="LINE";
  FKeys[1].KeyCode=VK_3;

  FKeys[3].KeyType=zxkNum;
  FKeys[3].KeyChar="4";
  FKeys[3].TopKeyword="INV VIDEO";
  FKeys[3].TopKeyword2="GREEN";
  FKeys[3].Symbol = "$";
  FKeys[3].BottomKeyword="OPEN #";
  FKeys[3].KeyCode=VK_4;

  FKeys[4].KeyType=zxkNum;
  FKeys[4].KeyChar="5";
  FKeys[4].TopKeyword="ï";
  FKeys[4].TopKeyword2="CYAN";
  FKeys[4].Symbol = "%";
  FKeys[4].BottomKeyword="CLOSE #";
  FKeys[4].KeyCode=VK_5;

  FKeys[5].KeyType=zxkNum;
  FKeys[5].KeyChar="6";
  FKeys[5].TopKeyword="ò";
  FKeys[5].TopKeyword2="YELLOW";
  FKeys[5].Symbol = "&";
  FKeys[5].BottomKeyword="MOVE";
  FKeys[5].KeyCode=VK_6;

  FKeys[6].KeyType=zxkNum;
  FKeys[6].KeyChar="7";
  FKeys[6].TopKeyword="ñ";
  FKeys[6].TopKeyword2="WHITE";
  FKeys[6].Symbol = "'";
  FKeys[6].BottomKeyword="ERASE";
  FKeys[6].KeyCode=VK_7;

  FKeys[7].KeyType=zxkNum;
  FKeys[7].KeyChar="8";
  FKeys[7].TopKeyword="ð";
  FKeys[7].TopKeyword2="";
  FKeys[7].Symbol = "(";
  FKeys[7].BottomKeyword="POINT";
  FKeys[7].KeyCode=VK_8;

  FKeys[8].KeyType=zxkNum;
  FKeys[8].KeyChar="9";
  FKeys[8].TopKeyword="GRAPHICS";
  FKeys[8].TopKeyword2="";
  FKeys[8].Symbol = ")";
  FKeys[8].BottomKeyword="CAT";
  FKeys[8].KeyCode=VK_9;

  FKeys[9].KeyType=zxkNum;
  FKeys[9].KeyChar="0";
  FKeys[9].TopKeyword="DELETE";
  FKeys[9].TopKeyword2="BLACK";
  FKeys[9].Symbol = "_";
  FKeys[9].BottomKeyword="FORMAT";
  FKeys[9].KeyCode=VK_0;

  FKeys[10].KeyType=zxkChar;
  FKeys[10].KeyChar="Q";
  FKeys[10].Keyword="PLOT";
  FKeys[10].TopKeyword="SIN";
  FKeys[10].TopKeyword2="";
  FKeys[10].Symbol = "<=";
  FKeys[10].BottomKeyword="ASN";
  FKeys[10].KeyCode = VK_Q;

  FKeys[11].KeyType=zxkChar;
  FKeys[11].KeyChar="W";
  FKeys[11].Keyword="DRAW";
  FKeys[11].TopKeyword="COS";
  FKeys[11].TopKeyword2="";
  FKeys[11].Symbol = "<>";
  FKeys[11].BottomKeyword="ACS";
  FKeys[11].KeyCode = VK_W;

  FKeys[12].KeyType=zxkChar;
  FKeys[12].KeyChar="E";
  FKeys[12].Keyword="REM";
  FKeys[12].TopKeyword="TAN";
  FKeys[12].TopKeyword2="";
  FKeys[12].Symbol = ">=";
  FKeys[12].BottomKeyword="ATN";
  FKeys[12].KeyCode = VK_E;

  FKeys[13].KeyType=zxkChar;
  FKeys[13].KeyChar="R";
  FKeys[13].Keyword="RUN";
  FKeys[13].TopKeyword="INT";
  FKeys[13].TopKeyword2="";
  FKeys[13].Symbol = "<";
  FKeys[13].BottomKeyword="VERIFY";
  FKeys[13].KeyCode = VK_R;

  FKeys[14].KeyType=zxkChar;
  FKeys[14].KeyChar="T";
  FKeys[14].Keyword="RAND";
  FKeys[14].TopKeyword="RND";
  FKeys[14].TopKeyword2="";
  FKeys[14].Symbol = ">";
  FKeys[14].BottomKeyword="MERGE";
  FKeys[14].KeyCode = VK_T;

  FKeys[15].KeyType=zxkChar;
  FKeys[15].KeyChar="Y";
  FKeys[15].Keyword="RETURN";
  FKeys[15].TopKeyword="STR $";
  FKeys[15].TopKeyword2="";
  FKeys[15].Symbol = "AND";
  FKeys[15].BottomKeyword="[";
  FKeys[15].KeyCode = VK_Y;

  FKeys[16].KeyType=zxkChar;
  FKeys[16].KeyChar="U";
  FKeys[16].Keyword="IF";
  FKeys[16].TopKeyword="CHR $";
  FKeys[16].TopKeyword2="";
  FKeys[16].Symbol = "OR";
  FKeys[16].BottomKeyword="]";
  FKeys[16].KeyCode = VK_U;

  FKeys[17].KeyType=zxkChar;
  FKeys[17].KeyChar="I";
  FKeys[17].Keyword="INPUT";
  FKeys[17].TopKeyword="CODE";
  FKeys[17].TopKeyword2="";
  FKeys[17].Symbol = "AT";
  FKeys[17].BottomKeyword="IN";
  FKeys[17].KeyCode = VK_I;

  FKeys[18].KeyType=zxkChar;
  FKeys[18].KeyChar="O";
  FKeys[18].Keyword="POKE";
  FKeys[18].TopKeyword="PEEK";
  FKeys[18].TopKeyword2="";
  FKeys[18].Symbol = ";";
  FKeys[18].BottomKeyword="OUT";
  FKeys[18].KeyCode = VK_O;

  FKeys[19].KeyType=zxkChar;
  FKeys[19].KeyChar="P";
  FKeys[19].Keyword="PRINT";
  FKeys[19].TopKeyword="TAB";
  FKeys[19].TopKeyword2="";
  FKeys[19].Symbol = "\"";
  FKeys[19].BottomKeyword="©";
  FKeys[19].KeyCode = VK_P;

  FKeys[20].KeyType=zxkChar;
  FKeys[20].KeyChar="A";
  FKeys[20].Keyword="NEW";
  FKeys[20].TopKeyword="READ";
  FKeys[20].TopKeyword2="";
  FKeys[20].Symbol = "STOP";
  FKeys[20].BottomKeyword="~";
  FKeys[20].KeyCode = VK_A;

  FKeys[21].KeyType=zxkChar;
  FKeys[21].KeyChar="S";
  FKeys[21].Keyword="SAVE";
  FKeys[21].TopKeyword="RESTORE";
  FKeys[21].TopKeyword2="";
  FKeys[21].Symbol = "NOT";
  FKeys[21].BottomKeyword="|";
  FKeys[21].KeyCode = VK_S;

  FKeys[22].KeyType=zxkChar;
  FKeys[22].KeyChar="D";
  FKeys[22].Keyword="DIM";
  FKeys[22].TopKeyword="DATA";
  FKeys[22].TopKeyword2="";
  FKeys[22].Symbol = "STEP";
  FKeys[22].BottomKeyword="\\";
  FKeys[22].KeyCode = VK_D;

  FKeys[23].KeyType=zxkChar;
  FKeys[23].KeyChar="F";
  FKeys[23].Keyword="FOR";
  FKeys[23].TopKeyword="SGN";
  FKeys[23].TopKeyword2="";
  FKeys[23].Symbol = "TO";
  FKeys[23].BottomKeyword="{";
  FKeys[23].KeyCode = VK_F;

  FKeys[24].KeyType=zxkChar;
  FKeys[24].KeyChar="G";
  FKeys[24].Keyword="GOTO";
  FKeys[24].TopKeyword="ABS";
  FKeys[24].TopKeyword2="";
  FKeys[24].Symbol = "THEN";
  FKeys[24].BottomKeyword="}";
  FKeys[24].KeyCode = VK_G;

  FKeys[25].KeyType=zxkChar;
  FKeys[25].KeyChar="H";
  FKeys[25].Keyword="GOSUB";
  FKeys[25].TopKeyword="SQR";
  FKeys[25].TopKeyword2="";
  FKeys[25].Symbol = "^";
  FKeys[25].BottomKeyword="CIRCLE";
  FKeys[25].KeyCode = VK_H;

  FKeys[26].KeyType=zxkChar;
  FKeys[26].KeyChar="J";
  FKeys[26].Keyword="LOAD";
  FKeys[26].TopKeyword="VAL";
  FKeys[26].TopKeyword2="";
  FKeys[26].Symbol = "-";
  FKeys[26].BottomKeyword="VAL $";
  FKeys[26].KeyCode = VK_J;

  FKeys[27].KeyType=zxkChar;
  FKeys[27].KeyChar="K";
  FKeys[27].Keyword="LIST";
  FKeys[27].TopKeyword="LEN";
  FKeys[27].TopKeyword2="";
  FKeys[27].Symbol = "+";
  FKeys[27].BottomKeyword="SCREEN $";
  FKeys[27].KeyCode = VK_K;

  FKeys[28].KeyType=zxkChar;
  FKeys[28].KeyChar="L";
  FKeys[28].Keyword="LET";
  FKeys[28].TopKeyword="USR";
  FKeys[28].TopKeyword2="";
  FKeys[28].Symbol = "=";
  FKeys[28].BottomKeyword="ATTR";
  FKeys[28].KeyCode = VK_L;

  FKeys[29].KeyType=zxkEnter;
  FKeys[29].KeyChar="ENTER";
  FKeys[29].KeyCode = VK_RETURN;

  FKeys[30].KeyType=zxkCS;
  FKeys[30].KeyChar="CAPS SHIFT";
  FKeys[30].KeyCode=VK_LSHIFT;

  FKeys[31].KeyType=zxkChar;
  FKeys[31].KeyChar="Z";
  FKeys[31].Keyword="COPY";
  FKeys[31].TopKeyword="LN";
  FKeys[31].TopKeyword2="";
  FKeys[31].Symbol = ":";
  FKeys[31].BottomKeyword="BEEP";
  FKeys[31].KeyCode=VK_Z;

  FKeys[32].KeyType=zxkChar;
  FKeys[32].KeyChar="X";
  FKeys[32].Keyword="CLEAR";
  FKeys[32].TopKeyword="EXP";
  FKeys[32].TopKeyword2="";
  FKeys[32].Symbol = "£";
  FKeys[32].BottomKeyword="INK";
  FKeys[32].KeyCode=VK_X;

  FKeys[33].KeyType=zxkChar;
  FKeys[33].KeyChar="C";
  FKeys[33].Keyword="CONT";
  FKeys[33].TopKeyword="LPRINT";
  FKeys[33].TopKeyword2="";
  FKeys[33].Symbol = "?";
  FKeys[33].BottomKeyword="PAPER";
  FKeys[33].KeyCode=VK_C;

  FKeys[34].KeyType=zxkChar;
  FKeys[34].KeyChar="V";
  FKeys[34].Keyword="CLS";
  FKeys[34].TopKeyword="LLIST";
  FKeys[34].TopKeyword2="";
  FKeys[34].Symbol = "/";
  FKeys[34].BottomKeyword="FLASH";
  FKeys[34].KeyCode=VK_V;

  FKeys[35].KeyType=zxkChar;
  FKeys[35].KeyChar="B";
  FKeys[35].Keyword="BORDER";
  FKeys[35].TopKeyword="BIN";
  FKeys[35].TopKeyword2="";
  FKeys[35].Symbol = "*";
  FKeys[35].BottomKeyword="BRIGHT";
  FKeys[35].KeyCode=VK_B;

  FKeys[36].KeyType=zxkChar;
  FKeys[36].KeyChar="N";
  FKeys[36].Keyword="NEXT";
  FKeys[36].TopKeyword="INKEY $";
  FKeys[36].TopKeyword2="";
  FKeys[36].Symbol = ",";
  FKeys[36].BottomKeyword="OVER";
  FKeys[36].KeyCode=VK_N;

  FKeys[37].KeyType=zxkChar;
  FKeys[37].KeyChar="M";
  FKeys[37].Keyword="PAUSE";
  FKeys[37].TopKeyword="PI";
  FKeys[37].TopKeyword2="";
  FKeys[37].Symbol = ".";
  FKeys[37].BottomKeyword="INVERSE";
  FKeys[37].KeyCode=VK_M;

  FKeys[38].KeyType=zxkSS;
  FKeys[38].KeyChar="SYMBOL SHIFT";
  FKeys[38].KeyCode=VK_LCONTROL;

  FKeys[39].KeyType=zxkSpace;
  FKeys[39].KeyChar="SPACE";
  FKeys[39].KeyCode=VK_SPACE;

  QPalette pal = palette();
  pal.setColor(QPalette::Background, QColor(26,26,26));
  this->setAutoFillBackground(true);
  this->setPalette(pal);

  /*test = new QLabel(this);
  test->setText(FKeys[4].TopKeyword);
  QFont f("Wingdings", 10);
  test->setFont(f);*/
}

void ZXKB::paintEvent(QPaintEvent *event) {
    int i,w,h,l;
    w = 50;
    l = 7;

    QPainter painter(this);

    painter.setPen(QPen(Qt::red,10));
    painter.drawLine(this->width()-130,this->height(),this->width()+10,25);
    painter.setPen(QPen(Qt::yellow,10));
    painter.drawLine(this->width()-120,this->height(),this->width()+20,25);
    painter.setPen(QPen(Qt::green,10));
    painter.drawLine(this->width()-110,this->height(),this->width()+30,25);
    painter.setPen(QPen(Qt::cyan,10));
    painter.drawLine(this->width()-100,this->height(),this->width()+40,25);

    painter.setRenderHint(QPainter::Antialiasing, true);

    // Numbers
    for(i=0;i<10;i++) {
        DrawNumberKey(&painter, l, i);
        l += w;
    }
    // Top row
    l = 27;
    for(i=10;i<20;i++) {
        DrawStandardKey(&painter, l, i, 80);
        l += w;
    }
    // Middle row
    l = 37;
    for(i=20;i<30;i++) {
        if(FKeys[i].KeyType == zxkEnter) DrawSpecialKey(&painter, zxkEnter, l, i, 140);
        else DrawStandardKey(&painter, l, i, 140);
        l += w;
    }
    // Bottom row
    l = 7;
    h = 195;
    for(i=30;i<40;i++) {
        if(FKeys[i].KeyType == zxkChar) {
            w = 50;
            DrawStandardKey(&painter, l, i, h);
        }
        if(FKeys[i].KeyType == zxkSS) {
            w = 50;
            DrawSpecialKey(&painter, zxkSS, l, i, h);
        }
        if(FKeys[i].KeyType == zxkCS) {
            w = 60;
            DrawSpecialKey(&painter, zxkCS, l, i, h);
        }
        if(FKeys[i].KeyType == zxkSpace) {
            w = 70;
            DrawSpecialKey(&painter, zxkSpace, l, i, h);
        }
        l += w;
    }
}

void ZXKB::DrawNumberKey(QPainter *p, int l, int i) {
    QColor trcolours[10];
    trcolours[0] = Qt::blue;
    trcolours[1] = Qt::red;
    trcolours[2] = Qt::magenta;
    trcolours[3] = Qt::green;
    trcolours[4] = Qt::cyan;
    trcolours[5] = Qt::yellow;
    trcolours[6] = Qt::white;
    trcolours[7] = Qt::white;
    trcolours[8] = Qt::white;
    trcolours[9] = Qt::black;
    QFont f("Arial",6);
    QFont bf("Arial",13);
    QFont rf("Arial",8);
    QFont sf("Wingdings",8);
    p->setFont(f);
    p->setPen(trcolours[i]);
    p->drawText(l,10,FKeys[i].TopKeyword2);
    p->setPen(Qt::white);
    if(i >= 4 && i <= 7) p->setFont(sf);
    p->drawText(l,20,FKeys[i].TopKeyword);
    p->setBrush(Qt::gray);
    p->setPen(Qt::black);
    p->drawRect(l,25,50,34);
    FKeys[i].ClickRect = QRect(l,25,50,34);
    p->setFont(bf);
    p->setPen(Qt::white);
    p->drawText(l+3,44,FKeys[i].KeyChar);
    p->setPen(Qt::red);
    p->setFont(rf);
    p->drawText(l+25,48,FKeys[i].Symbol);
    p->setFont(f);
    p->drawText(l+3,70,FKeys[i].BottomKeyword);
}

void ZXKB::DrawStandardKey(QPainter *p, int l, int i, int t) {
    QFont f("Arial",6);
    QFont bf("Arial",13);
    QFont rf("Arial",8);
    p->setPen(Qt::green);
    p->setFont(f);
    p->drawText(l,t+3,FKeys[i].TopKeyword);
    p->setBrush(Qt::gray);
    p->setPen(Qt::black);
    p->drawRect(l,t+5,50,34);
    FKeys[i].ClickRect = QRect(l,t+5,50,34);
    p->setFont(bf);
    p->setPen(Qt::white);
    p->drawText(l+3,t+22,FKeys[i].KeyChar);
    p->setPen(Qt::red);
    p->setFont(f);
    p->drawText(l+25,t+20,FKeys[i].Symbol);
    p->drawText(l+3,t+50,FKeys[i].BottomKeyword);
    p->setPen(Qt::white);
    p->setFont(rf);
    p->drawText(l+8,t+34,FKeys[i].Keyword);
}

void ZXKB::DrawSpecialKey(QPainter *p, TZXKeyType ty, int l, int i, int t) {
    int w;
    w = 50;
    if(ty == zxkCS) w = 60;
    if(ty == zxkSpace) w = 70;
    p->setBrush(Qt::gray);
    p->setPen(Qt::black);
    p->drawRect(l,t+5,w,34);
    FKeys[i].ClickRect = QRect(l,t+5,w,34);
    p->setPen(Qt::white);
    if(ty == zxkEnter) {
        p->setFont(QFont("Arial",10));
        p->drawText(l+3,t+27,FKeys[i].KeyChar);
    }
    if(ty == zxkCS) {
        p->setFont(QFont("Arial",10));
        p->drawText(l+11,t+21,"CAPS");
        p->drawText(l+11,t+35,"SHIFT");
    }
    if(ty == zxkSS) {
        p->setFont(QFont("Arial",8));
        p->setPen(Qt::red);
        p->drawText(l+3,t+19,"SYMBOL");
        p->drawText(l+10,t+33,"SHIFT");
    }
    if(ty == zxkSpace) {
        p->setFont(QFont("Arial",8));
        p->drawText(l+17,t+19,"BREAK");
        p->setFont(QFont("Arial",10));
        p->drawText(l+15,t+33,"SPACE");
    }
}

void ZXKB::mousePressEvent(QMouseEvent *event) {
    for(int i=0;i<40;i++) {
        if(FKeys[i].ClickRect.contains(event->pos())) {
            emit KeyDown(FKeys[i].KeyCode);
        }
    }
}

void ZXKB::mouseReleaseEvent(QMouseEvent *event) {
    for(int i=0;i<40;i++) {
        if(FKeys[i].ClickRect.contains(event->pos())) {
            emit KeyUp(FKeys[i].KeyCode);
        }
    }
}
