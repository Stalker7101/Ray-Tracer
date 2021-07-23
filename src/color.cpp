#ifndef COLOR_H
#define COLOR_H
    #include "../hdr/color.h"
#endif

void write_color(std::ostream& out, const color& pixel_color, int samples_per_pixel) {

    double r = pixel_color.x();
    double g = pixel_color.y();
    double b = pixel_color.z();

    // divide the color by the number of samples
    
    double scale = 1.0 / samples_per_pixel;
    r = std::sqrt(r * scale);
    g = std::sqrt(g * scale);
    b = std::sqrt(b * scale);

    // write the translated to [0, 255]
    // value of each color component
    out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}
