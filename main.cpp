#include <iostream>
#include "color.h"
#include "vec3.h"

int main() {

    // Image

    const int image_width = 800;
    const int image_height = 400;

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {

            // RGB form
            vec3 colors(
                (double(i) / (image_width)),
                (double(j) / (image_height)),
                0.25
            );

            print_color(std::cout, colors);
        }
    }
    std::cerr << "\nDone.\n";
}