#include <cmath>
#include "Explosion.h"

void Explosion::TryMove() {
    end_time = std::chrono::steady_clock::now();
    if (std::chrono::duration<double>(end_time - start_time).count() >= 0.5 && !end_of_line) {
        Move();
        start_time = std::chrono::steady_clock::now();
    }
}

void Explosion::Move() {
    if (cur_rad <= max_rad) {
        Draw();
        Erase();
        cur_rad++;
    }
    else {
        Erase();
        end_of_line = true;
    }
}

Explosion::Explosion(int x, int y, int minR, int max_rad) : e_x(x), e_y(y), minR(minR), max_rad(max_rad) {
    cur_rad = minR;
}

void Explosion::Draw() {
    for (int cur_y = e_y + cur_rad; cur_y >= e_y - cur_rad; --cur_y) {
        for (int cur_x = e_x - cur_rad; cur_x < e_x + (cur_rad + 0.4); ++cur_x) {
            if (sqrt(pow(cur_x - e_x, 2) + pow(cur_y - e_y, 2)) >= (cur_rad - 0.4) && sqrt(pow(cur_x - e_x, 2) + pow(cur_y - e_y, 2)) <= (cur_rad + 0.4)) {
                Figure::Draw(cur_x, cur_y, sym.SetValue());
            }
        }
    }
}

void Explosion::Erase() {
    for (int cur_y = e_y + (cur_rad - 1); cur_y >= e_y - (cur_rad - 1); --cur_y) {
        for (int cur_x = e_x - (cur_rad - 1); cur_x < e_x + ((cur_rad - 1) + 0.4); ++cur_x) {
            if (sqrt(pow(cur_x - e_x, 2) + pow(cur_y - e_y, 2)) >= ((cur_rad - 1) - 0.4) && sqrt(pow(cur_x - e_x, 2) + pow(cur_y - e_y, 2)) <= ((cur_rad - 1) + 0.4)) {
                Figure::Draw(cur_x, cur_y, ' ');
            }
        }
    }
}
