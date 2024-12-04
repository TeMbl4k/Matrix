#ifndef MATRIX_FIGURE_H
#define MATRIX_FIGURE_H

#include <tuple>
#include "Windows.h"
#include "Symbol.h"

class Figure {

protected:
    int X, Y;
    int width, height;

    std::pair<int, int> coordinates;
    Windows win;

public:
    const std::pair<int, int>& getCoordinates();
    void Draw(int x, int y, char symbol);
    virtual void TryMove() = 0;

    bool end_of_line = false;
    bool is_exploded = false;
};


#endif //MATRIX_FIGURE_H