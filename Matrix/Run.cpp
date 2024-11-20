#include <chrono>
#include <vector>
#include <algorithm>
#include <random>

#include "Run.h"
#include "Line.h"

void Run::Start(){
    while (true) {
        end_time = std::chrono::steady_clock::now();
        elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
        if (!points.empty()) {
            auto begin = points.begin();
            if (elapsed_time.count() >= *begin) {
                points.erase(begin);
                figures.push_back(new Line(line_length, line_speed, exp_prob, epilepsy));
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
                if ((*iter)->end_of_line) {
                    iter = figures.erase(iter);
                }
                else {
                    (*iter)->TryMove();
                    if ((*iter)->isExplod) {
                        figures.insert(figures.begin(), new Explosion((*iter)->getCoordinates().first, (*iter)->getCoordinates().second, min_rad, max_rad));
                    }
                    ++iter;
                }
            }
        }
    }
}


Run::Run(int line_length, int line_speed, int line_frequency, bool epilepsy, int expprob, int minrad, int maxrad) : line_length(line_length), line_speed(line_speed), line_frequency(line_frequency), epilepsy(epilepsy), exp_prob(expprob), min_rad(minrad), max_rad(maxrad) {

    Windows win;
    std::tie(width, height) = win.get_console_size();
    set_time_points();
    figures.reserve(line_frequency * line_speed * (height) * exp_prob);
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
    namespace sc = std::chrono;
    auto time = sc::system_clock::now(); // get the current time
    auto since_epoch = time.time_since_epoch(); // get the duration since epoch
    auto millis = sc::duration_cast<sc::nanoseconds>(since_epoch);

    std::random_device rd;
    std::mt19937 gen(millis.count());
    std::uniform_real_distribution<double> dis(a, b);

    double c = dis(gen);

    return c;
}

