#include <iostream>
#include "Line.h"

Line::Line(int line_length, int line_speed, int exp_prob, bool epilepsy) : line_length(line_length), line_speed((double)1.0 / line_speed), exp_prob(exp_prob), epilepsy(epilepsy) {
    std::tie(width, height) = win.get_console_size();

    x = 1 + rand() % (width - 2);
    y = 0;
}

void Line::TryMove() {
    isExplod = false;
    end_time = std::chrono::steady_clock::now();
    if (std::chrono::duration<double>(end_time - start_time).count() >= line_speed && !end_of_line) {
        Move();
        if (rand() % 1000 <= exp_prob) {
            isExplod = true;
        }
        start_time = std::chrono::steady_clock::now();
    }
}

void Line::Move() {
    if (y == height) {
        end = true;
    }
    if (y < height) {
        Draw();
        y++;
    }
    if (y - line_length == height) {
        end_of_line = true;
        this->~Line();
    }
    else {
        if (y >= line_length) {
            if (end) {
                y++;
            }
            Erase();
        }

    }
}

void Line::Draw() {
    Figure::Draw(x - (y % 2), y, sym.SetValue());
    if (y % 2 == 1) {
        Figure::Draw(x + (y % 2), y, sym.SetValue());
    }
}

void Line::Erase() {
    Figure::Draw(x - ((y - line_length) % 2), (y - line_length), ' ');
    if ((y - line_length) % 2 == 1) {
        Figure::Draw(x + ((y - line_length) % 2), (y - line_length), ' ');
    }
}