#ifndef APPMANAGER_H
#define APPMANAGER_H

#include <windows.h>

class AppManager {
private:
    int line_length, line_speed, line_frequency;
    int max_rad, min_rad, exp_prob;
    bool epilepsy;
    char epilepsy_flag;

public:
    void welcome();
    void startApp(int argc, char* argv[]);
};

#endif


