#ifndef MATRIX_EXPLOSION_H
#define MATRIX_EXPLOSION_H

#include <chrono>
#include "Figure.h"

class Explosion : public Figure {

    int e_x = 0, e_y = 0;
    int minR = 0, max_rad = 0, cur_rad = 0;

    Symbol sym = *new Symbol(true);
    std::chrono::time_point<std::chrono::steady_clock> start_time, end_time;

    void Move();

public:
    Explosion(int x, int y, int minR, int max_rad);
    void TryMove() override;
    void Draw();
    void Erase();

};


#endif //MATRIX_EXPLOSION_H
