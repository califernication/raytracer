#pragma once
#include <Vec3.h>

#include <iostream>

void print_color(std::ostream &out, Color pixel_color) {
    // Write the translated [0,255] value of each color component.
    out << int(255.999 * pixel_color.x()) << ' '
        << int(255.999 * pixel_color.y()) << ' '
        << int(255.999 * pixel_color.z()) << '\n';
}