#ifndef HITTABLE_H
#define HITTABLE_H
    #include "hittable.h"
#endif

#ifndef MEMORY
#define MEMORY
    #include <memory>
#endif

#ifndef VECTOR
#define VECTOR
    #include <vector>
#endif

class hittable_list : public hittable {

public:

    hittable_list() = default;
    hittable_list(const std::shared_ptr<const hittable>& object);

    void clear();
    void add(const std::shared_ptr<const hittable>& object);

    bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;

    ~hittable_list() override = default;

protected:

    std::vector<std::shared_ptr<const hittable>> objects;
};
