#ifndef IOSTREAM
#define IOSTREAM
    #include <iostream>
#endif

#ifndef FSTREAM
#define FSTREAM
    #include <fstream>
#endif

#ifndef MEMORY
#define MEMORY
    #include <memory>
#endif

#ifndef COLOR_H
#define COLOR_H
    #include "../hdr/color.h"
#endif

#ifndef VEC3_HPP
#define VEC3_HPP
    #include "../hdr/vec3.hpp"
#endif

#ifndef RAY_H
#define RAY_H
    #include "../hdr/ray.h"
#endif

#ifndef USEFUL_H
#define USEFUL_H
    #include "../hdr/useful.h"
#endif

#ifndef SPHERE_H
#define SPHERE_H
    #include "../hdr/sphere.h"
#endif

#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H
    #include "../hdr/hittable_list.h"
#endif

color ray_color(const ray& r, const hittable& world) {

    hit_record rec;

    if (world.hit(r, 0, infinity, rec)) {

        return 0.5 * static_cast<color>(rec.normal + vec3<>(1.0, 1.0, 1.0));
    }

    vec3<> unit_direction = unit_vector(r.direction());
    double t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

int main (int argc, char * argv[]) {

    std::string nameOfImage;
    std::cin >> nameOfImage;

    std::ofstream fout(nameOfImage, std::ios::app);

    // Image

    const double aspect_ratio = 16.0 / 9.0;
    const int image_width = 960;
    const int image_height
        = static_cast<int>(static_cast<double>(image_width) / aspect_ratio);

    // World
    
    hittable_list world;
    world.add(std::make_shared<sphere>(point3(0, 0, -1), 0.5));
    world.add(std::make_shared<sphere>(point3(0, -100.5, -1), 100));
    world.add(std::make_shared<sphere>(point3(1, 0, -2), 0.5));

    // Camera
    
    double viewport_height = 2.0;
    double viewport_width = aspect_ratio * viewport_height;
    double focal_length = 1.0;

    point3 origin(0, 0, 0);
    vec3<> horizontal(viewport_width, 0, 0);
    vec3<> vertical(0, viewport_height, 0);
    point3 lower_left_corner = origin - horizontal / 2 - vertical / 2
                               - vec3<>(0, 0, focal_length);

    // Render
    
    fout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height; j >= 0; --j) {

        std::cerr << "\nScanlines remaning: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {

            double u = static_cast<double>(i) / (image_width - 1);
            double v = static_cast<double>(j) / (image_height - 1);

            ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
            color pixel_color = ray_color(r, world);
            write_color(fout, pixel_color);
        }
    }

    std::cerr << "\nDone\n";

    return 0;
}
