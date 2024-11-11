#ifndef LINE_H
#define LINE_H

#include <windows.h>
#include <chrono>
#include "Symbol.h"
#include "cs.h"
#include "Windows.h"

class Line {

private:
    int line_length;
    double line_speed;
    bool epilepsy;

    int X = 0;
    int Y = 0;
    bool sc_end = false;
    Windows win;

    void Draw();
    void Erase();

    Symbol sym = *new Symbol(epilepsy);
    std::chrono::time_point<std::chrono::steady_clock> start_time, end_time;

public:
    void Move();

    class cs conSize;
    bool EOL = false;
    Line(int line_length, int line_speed, bool epilepsy);
    ~Line() { sym.~Symbol(); }

    void tryMove();
};


#endif 