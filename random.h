#pragma once

#include <random>

template<class T = double>
class triangular_distribution {
public:
    explicit triangular_distribution(T min, T mode, T max) :
            a{min}, b{mode}, c{max} {}

    T min() const { return a; }

    T mode() const { return b; }

    T max() const { return c; }

    template<class Generator>
    T operator()(Generator& g) {
        auto x = g();
        if (x <= b) {
            static T denominator = (b - a) * (c - a);
            return 2 * (x - a) / denominator;
        }
        static T denominator = (c - b) * (c - a);
        return 2 * (c - x) / denominator;
    }

private:
    T a, b, c;
};

static std::mt19937 &random_generator() {
    static std::random_device rd;
    static std::mt19937 generator{rd()};
    return generator;
}

template<class T>
T normal_random(T mean, T stddev) {
    static_assert(std::is_arithmetic<T>::value, "T must be arithmetic");
    std::normal_distribution<T> distribution{mean, stddev};
    return distribution(random_generator());
}

template<class T>
T uniform_random(T min, T max) {
    static_assert(std::is_arithmetic<T>::value, "T must be arithmetic");
    std::uniform_real_distribution<T> distribution{min, max};
    return distribution(random_generator());
}

template<class T>
T triangular_random(T min, T mode, T max) {
    static_assert(std::is_arithmetic<T>::value, "T must be arithmetic");
    triangular_distribution <T> distribution{min, max, mode};
    return distribution(random_generator());
}
