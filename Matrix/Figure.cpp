#include <cstdio>
#include "Figure.h"
#include <iostream>

using namespace std;

void Figure::Draw(int x, int y, char sym) {

    std::tie(width, height) = win.get_console_size();

    if (x > 0 && x < width && y > 0 && y < height) {
        win.SetPos(x, y);
        cout << sym;
    }
}

const std::pair<int, int> &Figure::getCoordinates() {
    coordinates.first = x;
    coordinates.second = y;
    return coordinates;
}
