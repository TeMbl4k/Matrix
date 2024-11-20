#ifndef MATRIX_EXPLOSION_H
#define MATRIX_EXPLOSION_H


#include <chrono>
#include "Figure.h"

class Explosion : public Figure {

    int e_x = 0, e_y = 0;
    int minR = 0, maxR = 0, curR = 0;
    Symbol sym = *new Symbol(true);
    std::chrono::time_point<std::chrono::steady_clock> start_time, end_time;

    void TryMove();

    void Move();

public:
    Explosion(int x, int y, int minR, int maxR);
    void Draw();
    void Erase();

    ~Explosion() { sym.~Symbol(); }
};


#endif //MATRIX_EXPLOSION_H
