#include <cstdio>
#include "Figure.h"

void Figure::Draw(int x, int y, char sym) {

    std::tie(width, height) = win.get_console_size();

    if (x > 0 && x < width && y > 0 && y < height) {
        win.SetPos(x, y);
        printf("%c", sym);
    }
}

const std::pair<int, int>& Figure::getCoordinates() {
    coordinates.first = x;
    coordinates.second = y;
    return coordinates;
}

//#include <cstdio>
//#include "Figure.h"
//
//void Figure::Print(int x, int y, char symbol) {
//    std::tie(width, height) = windows.get_console_size();
//    if (x > 0 && x < width && y > 0 && y < height) {
//        windows.SetPos(x, y);
//        printf("%c", symbol);
//    }
//}
//
//const std::pair<int, int>& Figure::getCoordinates() {
//    coordinates.first = X;
//    coordinates.second = Y;
//    return coordinates;
//}