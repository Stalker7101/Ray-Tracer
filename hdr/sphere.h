#ifndef HITTABLE_H
#define HITTABLE_H
    #include "hittable.h"
#endif

#ifndef VEC3_HPP
#define VEC3_HPP
    #include "vec3.hpp"
#endif

class sphere : public hittable {

public:

    sphere() = default;
    sphere(const point3& cen, double r);

    const point3& get_center() const;
    double get_radius() const;

    bool hit(const ray& r, double t_min, double t_max,
             hit_record& rec) const override;

    ~sphere() override = default;

protected:

    point3 center;
    double radius;
};
