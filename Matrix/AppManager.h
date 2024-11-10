#ifndef APPMANAGER_H
#define APPMANAGER_H

#include "Line.h"
#include <iostream>
#include <limits>
#include <windows.h>
#include "Windows.h"

class AppManager {
private:
    int line_speed, line_length, line_frequency;
    bool epilepsy;
    char epilepsy_flag;
    int width, height;
public:
    AppManager();
    void welcome();
    void run();
    void startApp(int argc, char* argv[]);
};

#endif // APPMANAGER_H
