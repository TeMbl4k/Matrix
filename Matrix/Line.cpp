#include <iostream>
#include <windows.h>
#include "Line.h"

Line::Line(int line_length, int line_speed, bool epilepsy) : line_length(line_length), line_speed((double)1.0 / line_speed), epilepsy(epilepsy) {
    conSize = win.getConsoleSize();
    X = 1 + rand() % (conSize.width - 2);
    Y = conSize.height - 1;
}

void Line::tryMove() {
    end_time = std::chrono::steady_clock::now();
    if (std::chrono::duration<double>(end_time - start_time).count() >= line_speed && !EOL) {
        Move();
        start_time = std::chrono::steady_clock::now();
    }
}
void Line::Move() {
    if (Y == 0) {
        sc_end = true;
    }
    if (Y > 0) {
        Draw();
        Y--;
    }
    if (Y + line_length == 1) {
        EOL = true;
        this->~Line();
    }
    else {
        if (Y <= conSize.height - line_length) {
            if (sc_end) {
                Y--;
            }
            Erase();
        }

    }
}

void Line::Draw() {
    win.SetPos(X - (Y % 2), Y);
    Symbol sym{ epilepsy };
    sym.display();
    if (Y % 2 == 1) {
        win.SetPos(X + (Y % 2), Y);
        Symbol sym{ epilepsy };
        sym.display();
    }
}

void Line::Erase() {
    win.SetPos(X - ((Y + line_length) % 2), (Y + line_length));
    std::cout << " ";
    if ((Y + line_length) % 2 == 1) {
        win.SetPos(X + ((Y + line_length) % 2), (Y + line_length));
        std::cout << " ";
    }
}