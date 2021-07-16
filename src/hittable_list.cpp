#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H
    #include "../hdr/hittable_list.h"
#endif

hittable_list::hittable_list(const std::shared_ptr<const hittable>& object) {

    add(object);
}

void hittable_list::add(const std::shared_ptr<const hittable>& object) {

    objects.push_back(object);
}

void hittable_list::clear() {

    objects.clear();
}

bool hittable_list::hit(const ray& r, double t_min,
                        double t_max, hit_record& rec) const {

    hit_record temp_rec;
    bool hit_anything = false;
    double closest_border = t_max;

    for (const auto& object : objects) {

        if (object->hit(r, t_min, closest_border, temp_rec)) {

            hit_anything = true;
            closest_border = temp_rec.t;
            rec = temp_rec;
        }
    }

    return hit_anything;
}
