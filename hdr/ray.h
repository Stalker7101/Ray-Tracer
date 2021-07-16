#ifndef VEC3_HPP
#define VEC3_HPP
    #include "vec3.hpp"
#endif

class ray {

public:

    ray() = default;
    ray(const point3& origin, const vec3<>& direction);

    const point3& origin() const;
    const vec3<>& direction() const;

    void change_origin(const point3& n_orig);
    void change_direction(const vec3<>& n_dir);
    
    point3 at(double t) const;

    ~ray() = default;

protected:

    point3 orig;
    vec3<> dir;
};
