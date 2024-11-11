#ifndef WINDOWS_H
#define WINDOWS_H


#include "cs.h"
#include <windows.h>

class Windows {

public:
    class cs getConsoleSize();
    void SetPos(int x, int y);
    void clean();

    void cls(void* hConsole);

    void hidecursor();
};


#endif