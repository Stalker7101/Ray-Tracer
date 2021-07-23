#ifndef MATERIAL_H
#define MATERIAL_H
    #include "material.h"
#endif

class lambertian : public material {

public:

    lambertian() = default;
    explicit lambertian(const color& a);
    
    const color& get_albedo() const;
    bool scatter(const ray& r_in, const hit_record& rec,
                 color& attenuation, ray& scattered) const override;

    ~lambertian() override = default;

protected:

    color albedo;
};
