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
    int frequency;
    int random_width;

    Windows Win;

public:
    Line(int len, int spd, bool epi, int freq);
    void Start(int line_length, int speed, bool ep);
};

#endif