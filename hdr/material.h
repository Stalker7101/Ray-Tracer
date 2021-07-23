#ifndef MEMORY
#define MEMORY
    #include <memory>
#endif

#ifndef RAY_H
#define RAY_H
    #include "ray.h"
#endif

#ifndef VEC3_HPP
#define VEC3_HPP
    #include "vec3.hpp"
#endif

#ifndef HITTABLE_H
#define HITTABLE_H
    #include "hittable.h"
#endif

struct hit_record;

class material {

public:

    material() = default;
    virtual bool scatter(const ray& r_in, const hit_record& rec,
                         color& attenuation, ray& scattered) const = 0;

    virtual ~material() = default;
};
