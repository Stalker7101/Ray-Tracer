#ifndef RAY_H
#define RAY_H
    #include "../hdr/ray.h"
#endif

ray::ray(const point3& origin, const vec3<>& direction)
    : orig(origin), dir(direction)
{}

const point3& ray::origin() const {

    return orig;
}

const vec3<>& ray::direction() const {

    return dir;
}

void ray::change_origin(const point3& n_orig) {

    orig = n_orig;
}

void ray::change_direction(const vec3<>& n_dir) {

    dir = n_dir;
}

point3 ray::at(const double t) const {

    return orig + t * dir;
}
