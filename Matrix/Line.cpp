#include <iostream>
#include "Line.h"


Line::Line(int line_length, int line_speed, int exp_prob, bool epilepsy)
    : line_length(line_length), line_speed((double)1.0 / line_speed), exp_prob(exp_prob), epilepsy(epilepsy) {

    std::tie(width, height) = win.get_console_size();
    X = 1 + rand() % (width - 2);
    Y = 0;
}

void Line::TryMove() {
    is_exploded = false;
    end_time = std::chrono::steady_clock::now();
    if (std::chrono::duration<double>(end_time - start_time).count() >= line_speed && !end_of_line) {
        Move();
        if (rand() % 10000 <= exp_prob) {
            is_exploded = true;
        }
        start_time = std::chrono::steady_clock::now();
    }
}


void Line::Move() {
    if (Y == height) {
        end = true;
    }
    if (Y < height) {
        Draw();
        Y++;
    }
    if (Y - line_length == height) {
        end_of_line = true;
        this->~Line();
    }
    else {
        if (Y >= line_length) {
            if (end) {
                Y++;
            }
            Erase();
        }

    }
}

void Line::Draw() {
    Figure::Draw(X - (Y % 2), Y, symbol.SetValue());
    if (Y % 2 == 1) {
        Figure::Draw(X + (Y % 2), Y, symbol.SetValue());
    }
}

void Line::Erase() {
    Figure::Draw(X - ((Y - line_length) % 2), (Y - line_length), ' ');
    if ((Y - line_length) % 2 == 1) {
        Figure::Draw(X + ((Y - line_length) % 2), (Y - line_length), ' ');
    }
}
