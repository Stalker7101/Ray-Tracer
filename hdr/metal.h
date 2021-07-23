#ifndef MATERIAL_H
#define MATERIAL_H
    #include "material.h"
#endif

class metal: public material {

public:

    metal() = default;
    explicit metal(const color& a, double fuzz);

    const color& get_albedo() const;
    double get_fuzz() const;
    bool scatter(const ray& r_in, const hit_record& rec,
                 color& attenuation, ray& scattered) const override;

    ~metal() override = default;

protected:

    color albedo;
    double fuzz;
};
