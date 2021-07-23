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

#ifndef CAMERA_H
#define CAMERA_H
    #include "../hdr/camera.h"
#endif

#ifndef LAMBERTIAL_H
#define LAMBERTIAL_H
    #include "../hdr/lambertian.h"
#endif

#ifndef METAL_H
#define METAL_H
    #include "../hdr/metal.h"
#endif

color ray_color(const ray& r, const hittable& world, int depth) {

    // if we've exceeded the ray bounce limit, no more light is gathered
    if (depth <= 0) {
        
        return color(0.0, 0.0, 0.0);
    }

    hit_record rec;

    if (world.hit(r, 0.001, infinity, rec)) {
        
        ray scattered;
        color attenuation;

        if (rec.mat_ptr->scatter(r, rec, attenuation, scattered)) {

            return attenuation * ray_color(scattered, world, depth - 1);
        }

        return color(0.0, 0.0, 0.0);
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
    const int image_width = 1920;
    const int image_height
        = static_cast<int>(static_cast<double>(image_width) / aspect_ratio);

    const int samples_per_pixel = 100;
    const int max_depth = 50;

    // World
    
    hittable_list world;

    auto material_ground = std::make_shared<lambertian>(color(0.8, 0.8, 0.0));
    auto material_center = std::make_shared<metal>(color(0.7, 0.3, 0.3), 0.0);
    auto material_left   = std::make_shared<lambertian>(color(0.4, 0.6, 0.3));
    auto material_right  = std::make_shared<metal>(color(0.8, 0.6, 0.2), 1.0);

    world.add(std::make_shared<sphere>(point3(0, -100.5, -1), 100, material_ground));
    world.add(std::make_shared<sphere>(point3(0, 0, -1), 0.5, material_center));
    world.add(std::make_shared<sphere>(point3(-1, 0, -1), 0.5, material_left));
    world.add(std::make_shared<sphere>(point3(1, 0, -1), 0.5, material_right));

    // Camera
    
    camera cam;
    
    // Render
    
    fout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height; j >= 0; --j) {

        std::cerr << "\nScanlines remaning: " << j << ' ' << std::flush;

        for (int i = 0; i < image_width; ++i) {

            color pixel_color(0.0, 0.0, 0.0);

            for (int s = 0; s < samples_per_pixel; ++s) {

                double u = (static_cast<double>(i) + random_double()) /
                            static_cast<double>(image_width - 1);

                double v = (static_cast<double>(j) + random_double()) /
                            static_cast<double>(image_height - 1);

                ray r = cam.get_ray(u, v);
                pixel_color += ray_color(r, world, max_depth);
            }

            write_color(fout, pixel_color, samples_per_pixel);
        }
    }

    std::cerr << "\nDone\n";

    return 0;
}
