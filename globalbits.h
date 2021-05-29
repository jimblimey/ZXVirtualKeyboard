#ifndef GLOBALBITS_H
#define GLOBALBITS_H

#include <windows.h>
#include <winuser.h>
#include <QString>
#include <QRect>

const UINT VK_0 = 48;
const UINT VK_1 = 49;
const UINT VK_2 = 50;
const UINT VK_3 = 51;
const UINT VK_4 = 52;
const UINT VK_5 = 53;
const UINT VK_6 = 54;
const UINT VK_7 = 55;
const UINT VK_8 = 56;
const UINT VK_9 = 57;
const UINT VK_A = 65;
const UINT VK_B = 66;
const UINT VK_C = 67;
const UINT VK_D = 68;
const UINT VK_E = 69;
const UINT VK_F = 70;
const UINT VK_G = 71;
const UINT VK_H = 72;
const UINT VK_I = 73;
const UINT VK_J = 74;
const UINT VK_K = 75;
const UINT VK_L = 76;
const UINT VK_M = 77;
const UINT VK_N = 78;
const UINT VK_O = 79;
const UINT VK_P = 80;
const UINT VK_Q = 81;
const UINT VK_R = 82;
const UINT VK_S = 83;
const UINT VK_T = 84;
const UINT VK_U = 85;
const UINT VK_V = 86;
const UINT VK_W = 87;
const UINT VK_X = 88;
const UINT VK_Y = 89;
const UINT VK_Z = 90;

enum TZXKeyType {zxkNum, zxkChar, zxkEnter, zxkCS, zxkSS, zxkSpace};

struct TZXKeys {
    QString KeyChar;
    TZXKeyType KeyType;
    QString TopKeyword;
    QString TopKeyword2;
    QString Keyword;
    QString Symbol;
    QString BottomKeyword;
    UINT KeyCode;
    QRect ClickRect;
};

#endif // GLOBALBITS_H
