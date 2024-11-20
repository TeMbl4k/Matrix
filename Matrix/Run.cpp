#include <chrono>
#include <vector>
#include <algorithm>
#include <random>

#include "Run.h"
#include "Line.h"

//void Run::Start() {
//    while (true) {
//        end_time = std::chrono::steady_clock::now();
//        elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
//        if (!points.empty()) {
//            auto begin = points.begin();
//            if (elapsed_time.count() >= *begin) {
//                points.erase(begin);
//                lines.emplace_back(line_length+1, line_speed, epilepsy);
//            }
//        }
//
//        end_time = std::chrono::steady_clock::now();
//        elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
//        if (elapsed_time.count() > 1) {
//            start_time = std::chrono::steady_clock::now();
//            points.clear();
//            set_time_points();
//        }
//        if (!lines.empty()) {
//            for (auto iter = lines.begin(); iter != lines.end();) {
//                if (iter->end_of_line) {
//                    iter = lines.erase(iter);
//                }
//                else {
//                    iter->tryPrint();
//                    ++iter;
//                }
//            }
//        }
//    }
//}

void Run::Start() {
    while (true) {
        end_time = std::chrono::steady_clock::now();
        elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        if (!points.empty()) {
            auto begin = points.begin();
            if (elapsed_time.count() >= *begin) {
                points.erase(begin);
                figures.push_back(new Line(line_length + 1, line_speed, exp_prob, epilepsy));
            }
        }
        end_time = std::chrono::steady_clock::now();
        elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        if (elapsed_time.count() > 1) {
            start_time = std::chrono::steady_clock::now();
            points.clear();
            set_time_points();
        }
        if (!figures.empty()) {
            for (auto iter = figures.begin(); iter != figures.end();) {
                if ((*iter)->EOL) {
                    figures.erase(iter);
                }
                else {
                    (*iter)->TryMove();
                    if ((*iter)->isExplod) {
                        figures.push_back(new Explosion((*iter)->getCoordinates().first, (*iter)->getCoordinates().second, min_rad, max_rad));
                    }
                    ++iter;
                }
            }
        }
    }
}


Run::Run(int line_length, int line_speed, int line_frequency, bool epilepsy, int exp_prob, int min_rad, int max_rad) : line_length(line_length), line_speed(line_speed), line_frequency(line_frequency), epilepsy(epilepsy), exp_prob(exp_prob), min_rad(min_rad), max_rad(max_rad) {

    std::tie(width, height) = win.get_console_size();

    figures.reserve(line_frequency * line_speed * (height) * exp_prob);
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

