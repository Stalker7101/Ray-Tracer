#ifndef LAMBERTIAN_H
#define LAMBERTIAN_H
    #include "../hdr/lambertian.h"
#endif

lambertian::lambertian(const color& a)
    : albedo(a)
{}

bool lambertian::scatter(const ray& r_in, const hit_record& rec,
             color& attenuation, ray& scattered) const {
    
    vec3<> scatter_direction = rec.normal + vec3<>::random_unit_vector();

    // catch degenerate scatter direction
    if (scatter_direction.near_zero()) {
        scatter_direction = rec.normal;
    }

    scattered = ray(rec.p, scatter_direction);
    attenuation = albedo;

    return true;
}

const color& lambertian::get_albedo() const {

    return albedo;
}
