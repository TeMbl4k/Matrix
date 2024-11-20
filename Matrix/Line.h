#ifndef LINE_H
#define LINE_H

#include <chrono>
#include <tuple>
#include "Symbol.h"
#include "Windows.h"
#include "Figure.h"

class Line : public Figure {

private:
    int line_length;
    double line_speed;
    bool epilepsy;

    int width;
    int height;

    int max_rad, min_rad, exp_prob;

    int x = 0;
    int y = 0;

    bool end = false;

    Windows win;

    void Draw();
    void Erase();
    void Move();

    Symbol sym = *new Symbol(epilepsy);
    std::chrono::time_point<std::chrono::steady_clock> start_time, end_time;

public:
    Line(int line_lenght, int line_speed, int exp_prob, bool epilepsy);
    void TryMove() override;
    ~Line() { sym.~Symbol(); }
};


#endif 