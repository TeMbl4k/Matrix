#ifndef RUN_H
#define RUN_H

#include <windows.h>
#include <chrono>
#include <vector>
#include "Line.h"
#include "Explosion.h"


class Run {
    int line_length = 0;
    int line_speed = 0;
    int line_frequency = 0;
    bool epilepsy = false; 
    int max_rad = 0;
    int min_rad = 0;
    int exp_prob = 0;

    Windows win;

    int height, width;

    std::vector<Figure*> figures;
    std::vector<double> points;
    std::chrono::time_point<std::chrono::steady_clock> start_time, end_time;
    std::chrono::duration<double> elapsed_time;

public:
    Run(int line_length, int line_speed, int line_frequency, bool epilepsy, int expprob, int minrad, int maxrad);
    void Start();

    void set_time_points();

    double rand_double(double a, double b);
};


#endif