#ifndef COLOR_H
#define COLOR_H
    #include "../hdr/color.h"
#endif

void write_color(std::ostream& out, const color& pixel_color) {

    // write the translated to [0, 255]
    // value of each color component
    out << static_cast<int>(255.999 * pixel_color.x()) << ' '
        << static_cast<int>(255.999 * pixel_color.y()) << ' '
        << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}
