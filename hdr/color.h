#ifndef IOSTREAM
#define IOSTREAM
    #include <iostream>
#endif

#ifndef VEC3_HPP
#define VEC3_HPP
    #include "vec3.hpp"
#endif

#ifndef USEFUL_H
#define USEFUL_H
    #include "useful.h"
#endif

#ifndef CMATH
#define CMATH
    #include <cmath>
#endif

void write_color(std::ostream& out, const color& pixel_color, int samples_per_pixel);
