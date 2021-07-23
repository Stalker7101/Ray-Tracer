#ifndef SPHERE_H
#define SPHERE_H
    #include "../hdr/sphere.h"
#endif

sphere::sphere(const point3& cen, double r, const std::shared_ptr<const material>& m)
    : center(cen), radius(r), mat_ptr(m)
{}

const point3& sphere::get_center() const {

    return center;
}

double sphere::get_radius() const {

    return radius;
}

const std::shared_ptr<const material>& sphere::get_material() const {

    return mat_ptr;
}

bool sphere::hit(const ray& r, double t_min,
                 double t_max, hit_record& rec) const {

    vec3<> oc = r.origin() - center;
    double a = r.direction().length_squared();
    double half_b = dot(r.direction(), oc);
    double c = oc.length_squared() - radius * radius;

    double discriminant = half_b * half_b - a * c;

    if (discriminant < 0) { return false; }

    double sqrtd = std::sqrt(discriminant);

    // find the nearest root that
    // lies in acceptable range
    double root = (-half_b - sqrtd) / a;

    if ((root < t_min) || (root > t_max)) {

        root = (-half_b + sqrtd) / a;

        if ((root < t_min) || (root > t_max)) {

            return false;
        }
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    vec3<> outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);
    rec.mat_ptr = mat_ptr;

    return true;
}
