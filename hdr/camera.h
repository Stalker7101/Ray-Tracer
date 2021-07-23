#ifndef USEFUL_H
#define USEFUL_H
    #include "useful.h"
#endif

#ifndef RAY_H
#define RAY_H
    #include "ray.h"
#endif

class camera {

public:

    camera();
    ray get_ray(double u, double v) const;
    ~camera() = default;

protected:

    point3 origin;
    point3 lower_left_corner;
    vec3<> horizontal;
    vec3<> vertical;
};
