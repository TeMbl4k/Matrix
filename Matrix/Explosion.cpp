#include <cmath>
#include "Explosion.h"

void Explosion::TryMove() {
    end_time = std::chrono::steady_clock::now();
    if (std::chrono::duration<double>(end_time - start_time).count() >= 0.5 && !EOL) {
        Move();
        start_time = std::chrono::steady_clock::now();
    }
}

void Explosion::Move() {
    if (curR <= maxR) {
        Draw();
        Erase();
        curR++;
    }
    else {
        Erase();
        EOL = true;
        this->~Explosion();
    }
}

Explosion::Explosion(int x, int y, int minR, int maxR) : e_x(x), e_y(y), minR(minR), maxR(maxR) {
    curR = minR;
}

void Explosion::Draw() {
    for (int curY = e_y + curR; curY >= e_y - curR; --curY) {
        for (int curX = e_x - curR; curX < e_x + (curR + 0.4); ++curX) {
            if (sqrt(pow(curX - e_x, 2) + pow(curY - e_y, 2)) >= (curR - 0.4) && sqrt(pow(curX - e_x, 2) + pow(curY - e_y, 2)) <= (curR + 0.4)) {
                Symbol sym2{ true };
                Figure::Print(curX, curY, sym.Disp());
            }
        }
    }
}

void Explosion::Erase() {
    for (int curY = e_y + (curR - 1); curY >= e_y - (curR - 1); --curY) {
        for (int curX = e_x - (curR - 1); curX < e_x + ((curR - 1) + 0.4); ++curX) {
            if (sqrt(pow(curX - e_x, 2) + pow(curY - e_y, 2)) >= ((curR - 1) - 0.4) && sqrt(pow(curX - e_x, 2) + pow(curY - e_y, 2)) <= ((curR - 1) + 0.4)) {
                Figure::Print(curX, curY, ' ');
            }
        }
    }
}
