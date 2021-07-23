#ifndef CMATH
#define CMATH
    #include <cmath>
#endif

#ifndef LIMITS
#define LIMITS
    #include <limits>
#endif

#ifndef RANDOM
#define RAMDOM
    #include <random>
#endif

// constants

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// useful functions

inline double degrees_to_radians(double degrees) {

    return degrees * (pi / 180);
}

inline double random_double() {

    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

inline double random_double(double min, double max) {

    static std::uniform_real_distribution<double> distribution(min, max);
    static std::mt19937 generator;
    return distribution(generator);
}

inline double clamp(double x, double min, double max) {

    if (x < min) return min;
    if (x > max) return max;
    return x;
}
