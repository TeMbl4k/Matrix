#ifndef MATRIX_WINDOWS_H
#define MATRIX_WINDOWS_H

#include <windows.h>
#include <utility>


class Windows {

public:
    std::pair<int, int> get_console_size();
    void GotoXY(int x, int y);
    void clean();

    void cls(void* hConsole);

    void hidecursor();
};


#endif //MATRIX_WINDOWS_H
