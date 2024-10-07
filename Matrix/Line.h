#ifndef LINE_H
#define LINE_H

#include "Symbol.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>

class Line {
public:
    int length;
    int speed;
    bool epilepsy;

    Line(int len, int spd, bool epi);
    void printRomb(int startX, int startY);
    void clearRomb(int startX, int startY);
    void printLine(int startY, int width);
};

#endif // LINE_H
