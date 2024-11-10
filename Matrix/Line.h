#ifndef LINE_H
#define LINE_H

#include "Symbol.h"
#include "Windows.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <windows.h>

class Line {
private:
    int length;
    int speed;
    bool epilepsy;

    Windows Win;

public:
    Line(int len, int spd, bool epi);
    void Start(int line_length, int speed, bool ep, int height, int width);
};

#endif