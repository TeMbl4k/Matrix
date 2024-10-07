#ifndef APPMANAGER_H
#define APPMANAGER_H

#include "Line.h"
#include <iostream>
#include <limits>
#include <windows.h>

class AppManager {
public:
    int line_speed, line_length;
    bool epilepsy;
    char epilepsy_flag;
    int width, height;

    AppManager();
    void welcome();
    void run();
    void startApp(int argc, char* argv[]);
};

#endif // APPMANAGER_H
