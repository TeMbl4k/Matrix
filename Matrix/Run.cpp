#include <chrono>
#include <vector>
#include <algorithm>
#include <random>

#include "Run.h"
#include "Line.h"


Run::Run(int line_length, int line_speed, int line_frequency, bool epilepsy) : line_length(line_length), line_speed(line_speed), line_frequency(line_frequency), epilepsy(epilepsy) {
    start_time = std::chrono::steady_clock::now();
    rand_tp();
    Start();
}

void Run::Start() {
    while (true) {
        end_time = std::chrono::steady_clock::now();
        elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        if (!points.empty()) {
            if (elapsed_time.count() >= points[0]) {
                points.erase(points.begin());
                Line line1(line_length + 1, line_speed, epilepsy);
                lines.push_back(line1);
            }
        }

        if (elapsed_time.count() >= 1) {
            rand_tp();
            start_time = std::chrono::steady_clock::now();
        }
        
        for (int i = 0; i < lines.size(); i++)
            if (lines[i].end_of_line)
                lines.erase(lines.begin() + i--);
            else
                lines[i].PrintTry();
    }
}

void Run::rand_tp() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis((double)0, (double)1);
   
    for (size_t i = 0; i < line_frequency; i++) {
        points.push_back(dis(gen));
    }
    std::sort(begin(points), end(points));
}

