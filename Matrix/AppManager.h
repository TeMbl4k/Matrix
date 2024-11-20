#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <windows.h>
#include "Welcome.h"

class AppManager {
private:
    int line_length;
    int line_speed;
    int line_frequency;
    bool epilepsy;
    char epilepsy_flag;
    int max_rad, min_rad, exp_prob;

public:
    void welcome();
    void startApp(int argc, char* argv[]);
};

#endif

