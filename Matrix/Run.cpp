#include <chrono>
#include <random>

#include "Run.h"
#include "Line.h"

void Run::Start() {
    while (true) {
        end_time = std::chrono::steady_clock::now();
        elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

        if (!points.empty()) {
            if (elapsed_time.count() >= points[0]) {
                figures.push_back(new Line(line_length + 1, line_speed, exp_prob, epilepsy));
                points.erase(0);
            }
        }

        if (elapsed_time.count() > 1) {
            start_time = std::chrono::steady_clock::now();
            points.clear();
            rand_points();
        }

        if (!figures.empty()) {
            for (int i = 0; i < figures.size(); i++) {
                if (figures[i]->end_of_line)
                    figures.erase(i--);
                else {
                    figures[i]->TryMove();
                    if (figures[i]->is_exploded) {
                        figures.push_back(new Explosion(figures[i]->getCoordinates().first, figures[i]->getCoordinates().second, min_rad, max_rad));
                    }
                }
            }
        }
    }
}

Run::Run(int line_length, int line_speed, int line_freq, bool epilepsy, int exp_prob, int min_rad, int max_rad)
    : line_length(line_length), line_speed(line_speed), line_freq(line_freq),
    epilepsy(epilepsy), exp_prob(exp_prob),
    min_rad(min_rad), max_rad(max_rad) {

    Windows win;

    std::tie(width, height) = win.get_console_size();
    rand_points();
    start_time = std::chrono::steady_clock::now();
    Start();
}

void Run::rand_points() {
    namespace sc = std::chrono;
    auto time = sc::system_clock::now();
    auto since_epoch = time.time_since_epoch();
    auto millis = sc::duration_cast<sc::nanoseconds>(since_epoch);

    std::random_device rd;
    std::mt19937 gen(millis.count());
    std::uniform_real_distribution<double> dis(0.0, 1.0);

    for (size_t i = 0; i < line_freq; i++) {
        points.push_back(dis(gen));
    }

    for (size_t i = 0; i < points.size(); i++) {
        for (size_t j = i + 1; j < points.size(); j++) {
            if (points[i] > points[j]) {
                std::swap(points[i], points[j]);
            }
        }
    }
}

