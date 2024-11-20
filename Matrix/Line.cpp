#include <iostream>
#include <windows.h>
#include "Line.h"

Line::Line(int line_length, int line_speed, bool epilepsy) : line_length(line_length), line_speed(1000/ line_speed), epilepsy(epilepsy) {
    std::tie(width, height) = win.get_console_size();
    x = rand() % (width - 2) + 1;
    y = 0;
}

void Line::PrintTry() {
    end_time = std::chrono::steady_clock::now();
    if (!end_of_line && std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count() >= line_speed) {
        PrintLine();
        start_time = std::chrono::steady_clock::now();
    }
}

void Line::PrintLine() {
    if (y == height) {
        end = true;
    }
    if (y < height) {
        PrintSym();
        y++;
    }
    if (y - line_length == height) {
        end_of_line = true;
    }
    else {
        if (y >= line_length) {
            if (end) {
                y++;
            }
            Clean();
        }

    }
}

void Line::PrintSym() {
    win.SetPos(x - (y % 2), y);
    Symbol sym1{ epilepsy };
    sym1.display();
    if (y % 2 == 1) {
        win.SetPos(x + (y % 2), y);
        Symbol sym2{ epilepsy };
        sym2.display();
    }
}

void Line::Clean() {
    win.SetPos(x - ((y - line_length) % 2), (y - line_length));
    std::cout << " ";
    if ((y - line_length) % 2 == 1) {
        win.SetPos(x + ((y - line_length) % 2), (y - line_length));
        std::cout << " ";
    }
}