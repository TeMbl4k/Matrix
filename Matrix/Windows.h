#ifndef WINDOWS_H
#define WINDOWS_H


#include "cs.h"
#include <windows.h>
#include <utility>

class Windows {

public:
    void cls(void* hConsole);
    std::pair<int, int> get_console_size();
    void SetPos(int x, int y);
    void clean();
    void hidecursor();
};


#endif