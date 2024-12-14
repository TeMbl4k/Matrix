#ifndef MATRIX_RUN_H
#define MATRIX_RUN_H

#include <chrono>
#include <vector>
#include "Line.h"
#include "Explosion.h"
#include "LinkedList.h"
#include "ArrayList.h"

class Run {
    int line_length = 0;
    int line_speed = 0;
    int line_freq = 0;
    int exp_prob = 0;
    int min_rad = 0;
    int max_rad = 0;
    bool epilepsy = false;

    int height, width;

    ArrayList<Figure*> figures;
    ArrayList<double> points;


    //std::vector<Figure*> figures;
    //std::vector<double> points;
    std::chrono::time_point<std::chrono::steady_clock> start_time, end_time;
    std::chrono::duration<double> elapsed_time;

public:
    Run(int line_length, int line_speed, int line_freq, bool epilepsy, int exp_prob, int min_rad, int max_rad);
    void Start();
    void rand_points();
};

#endif //MATRIX_RUN_H
