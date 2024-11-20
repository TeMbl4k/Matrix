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
        this->~Explosion();
    }
}

Explosion::Explosion(int x, int y, int min_rad, int max_rad) : e_x(x), e_y(y), min_rad(min_rad), max_rad(max_rad) {
    cur_rad = min_rad;
}

void Explosion::Draw() {
    for (int curY = e_y + cur_rad; curY >= e_y - cur_rad; --curY) {
        for (int curX = e_x - cur_rad; curX < e_x + (cur_rad + 0.4); ++curX) {
            if (sqrt(pow(curX - e_x, 2) + pow(curY - e_y, 2)) >= (cur_rad - 0.4) && sqrt(pow(curX - e_x, 2) + pow(curY - e_y, 2)) <= (cur_rad + 0.4)) {
                Figure::Draw(curX, curY, sym.SetValue());
            }
        }
    }
}

void Explosion::Erase() {
    for (int curY = e_y + (cur_rad - 1); curY >= e_y - (cur_rad - 1); --curY) {
        for (int curX = e_x - (cur_rad - 1); curX < e_x + ((cur_rad - 1) + 0.4); ++curX) {
            if (sqrt(pow(curX - e_x, 2) + pow(curY - e_y, 2)) >= ((cur_rad - 1) - 0.4) && sqrt(pow(curX - e_x, 2) + pow(curY - e_y, 2)) <= ((cur_rad - 1) + 0.4)) {
                Figure::Draw(curX, curY, ' ');
            }
        }
    }
}