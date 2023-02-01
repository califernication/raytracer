#pragma once
#include "Vec3.h"

#include <iostream>

void printColor(std::ostream &out, Color pixelColor) {
    // Write the translated [0,255] value of each color component.
    out << int(255.999 * pixelColor.x()) << ' '
        << int(255.999 * pixelColor.y()) << ' '
        << int(255.999 * pixelColor.z()) << '\n';
}