#ifndef MATRIX_LINE_H
#define MATRIX_LINE_H


#include <chrono>
#include "Symbol.h"
#include "cs.h"
#include "Windows.h"
#include "Figure.h"

class Line : public Figure {

private:
    int width, height;
    int line_length;
    double line_speed;
    int exp_prob;

    bool epilepsy;
    bool end = false;


    Symbol symbol = *new Symbol(epilepsy);
    std::chrono::time_point<std::chrono::steady_clock> start_time, end_time;

    void Draw();
    void Erase();
    void Move();

public:
    Line(int line_length, int line_speed, int exp_prob, bool epilepsy);
    void TryMove() override;

    ~Line() { symbol.~Symbol(); }
};


#endif //MATRIX_LINE_H
