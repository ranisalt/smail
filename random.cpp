#include <cmath>
#include <random>
#include "random.h"

template<class T = double>
class triangular_distribution {
public:
    explicit triangular_distribution(double min, double mode, double max) :
            a{min}, b{mode}, c{max} {}

    template<class Generator>
    double operator()(Generator& g) {
        auto rand = static_cast<double>(g()) / g.max();
        if (rand < static_cast<double>(c - a) / (b - a)) {
            return a + std::sqrt(rand * ((b - a) * (c - a)));
        }
        return b - std::sqrt((1 - rand) * ((b - a) * (b - c)));
    }

private:
    double a, b, c;
};

static std::mt19937& random_generator() {
    static std::random_device rd;
    static std::mt19937 generator{rd()};
    return generator;
}

double exponential_random(double lambda) {
    std::exponential_distribution<double> distribution{lambda};
    return distribution(random_generator());
}

double normal_random(double mean, double stddev) {
    std::normal_distribution<double> distribution{mean, stddev};
    return distribution(random_generator());
}

double uniform_random(double min, double max) {
    std::uniform_real_distribution<double> distribution{min, max};
    return distribution(random_generator());
}

double triangular_random(double min, double mode, double max) {
    triangular_distribution<double> distribution{min, max, mode};
    return distribution(random_generator());
}
