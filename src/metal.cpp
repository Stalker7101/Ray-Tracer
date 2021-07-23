#ifndef METAL_H
#define METAL_H
    #include "../hdr/metal.h"
#endif

metal::metal(const color& a, double f)
    : albedo(a), fuzz(f < 1 ? f : 1)
{}

bool metal::scatter(const ray& r_in, const hit_record& rec,
             color& attenuation, ray& scattered) const {

    vec3<> reflected = vec3<>::reflect(unit_vector(r_in.direction()), rec.normal); 
    scattered = ray(rec.p, reflected + fuzz * vec3<>::random_in_unit_spheree());
    attenuation = albedo;
    return (dot(scattered.direction(), rec.normal) > 0.0);
}

const color& metal::get_albedo() const {
    
    return albedo;
}

double metal::get_fuzz() const {
    
    return fuzz;
}
