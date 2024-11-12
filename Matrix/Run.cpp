#include <chrono>
#include <vector>
#include <algorithm>
#include <random>

#include "Run.h"
#include "Line.h"

void Run::Start() {
    while (true) {
        end_time = std::chrono::steady_clock::now();
        elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        if (!points.empty()) {
            auto begin = points.begin();
            if (elapsed_time.count() >= *begin) {
                points.erase(begin);
                lines.emplace_back(line_length+1, line_speed, epilepsy);
            }
        }

        end_time = std::chrono::steady_clock::now();
        elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        if (elapsed_time.count() > 1) {
            start_time = std::chrono::steady_clock::now();
            points.clear();
            set_time_points();
        }
        if (!lines.empty()) {
            for (auto iter = lines.begin(); iter != lines.end();) {
                if (iter->end_of_line) {
                    iter = lines.erase(iter);
                }
                else {
                    iter->tryPrint();
                    ++iter;
                }
            }
        }
    }
}

Run::Run(int line_length, int line_speed, int line_frequency, bool epilepsy) : line_length(line_length), line_speed(line_speed), line_frequency(line_frequency), epilepsy(epilepsy) {
    set_time_points();
    start_time = std::chrono::steady_clock::now();
    Start();
}

void Run::set_time_points() {
    for (size_t i = 0; i < line_frequency; i++) {
        points.push_back(rand_double((double)0, (double)1));
    }
    std::sort(begin(points), end(points));
}

double Run::rand_double(double a, double b) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(a, b);
    return dis(gen);
}

