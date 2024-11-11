#ifndef RUN_H
#define RUN_H

#include <windows.h>
#include <chrono>
#include <vector>
#include "Line.h"

class Run {
    int line_length;
    int line_speed;
    int line_frequency;
    bool epilepsy;

    std::vector<Line> lines;
    std::vector<double> points;
    std::chrono::time_point<std::chrono::steady_clock> start_time, end_time;
    std::chrono::duration<double> elapsed_time;

public:
    Run(int line_length, int line_speed, int line_frequency, bool epilepsy);
    void Start();

    void set_time_points();

    double rand_double(double a, double b);
};


#endif