#ifndef MATRIX_EXPLOSION_H
#define MATRIX_EXPLOSION_H


#include <chrono>
#include "Figure.h"

class Explosion : public Figure {

    int e_x = 0, e_y = 0;
    int min_rad = 0, max_rad = 0, cur_rad = 0;
    Symbol sym = *new Symbol(true);
    std::chrono::time_point<std::chrono::steady_clock> start_time, end_time;

    void Move();

public:
    Explosion(int x, int y, int minR, int maxR);
    void TryMove() override;
    void Draw();
    void Erase();

    ~Explosion() { sym.~Symbol(); }
};


#endif //MATRIX_EXPLOSION_H