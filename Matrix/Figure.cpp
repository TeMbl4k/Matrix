#include <cstdio>
#include "Figure.h"
#include <iostream>

using namespace std;

void Figure::Draw(int x, int y, char symbol) {
    Windows win;
    std::tie(width, height) = win.get_console_size();

    if (x > 0 && x < width && y > 0 && y < height) {
        win.GotoXY(x, y);
        cout << symbol;
    }
}

const std::pair<int, int>& Figure::getCoordinates() {
    coordinates.first = X;
    coordinates.second = Y;
    return coordinates;
}
