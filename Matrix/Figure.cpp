#include <cstdio>
#include "Figure.h"

void Figure::Print(int x, int y, char symbol) {
    std::tie(width, height) = windows.get_console_size();
    if (x > 0 && x < width && y > 0 && y < height) {
        windows.SetPos(x, y);
        printf("%c", symbol);
    }
}

const std::pair<int, int>& Figure::getCoordinates() {
    coordinates.first = X;
    coordinates.second = Y;
    return coordinates;
}