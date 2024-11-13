#ifndef LINE_H
#define LINE_H

#include <windows.h>
#include <chrono>
#include <tuple>
#include "Symbol.h"
#include "cs.h"
#include "Windows.h"

class Line {

private:
    int line_length;
    //double line_speed;
    int line_speed;
    bool epilepsy;
    int width;
    int height;

    int x = 0;
    int y = 0;
    bool end = false;
    Windows win;

    void PrintSym();
    void Clean();

    Symbol sym = *new Symbol(epilepsy);
    std::chrono::time_point<std::chrono::steady_clock> start_time, end_time;

public:
    bool end_of_line = false;
    Line(int line_length, int line_speed, bool epilepsy);
    void PrintTry();
    void PrintLine();
};


#endif 