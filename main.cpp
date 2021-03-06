#include <iostream>

#include "color.h"
#include "vec3.h"
#include "vec3-utility.h"
#include "ray.h"

double hit_sphere(const point& center, double radius, const ray& r) {
    vec3 oc = r.origin() - center;
    auto a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_squared() - radius*radius;
    auto discriminant = half_b*half_b - a*c;

    if (discriminant < 0) { // Check if negative root
        return -1.0;
    } else {
        return (-half_b - sqrt(discriminant) ) / a; // else retun the value
    }
}

color ray_color(const ray& r) {
    double t = hit_sphere(point(0,0,-1), 0.5, r);
    if (t > 0.0) {
        vec3 unit = unit_vector(r.at(t) - vec3(0,0,-1));
        return 0.5*color(unit.x()+1, unit.y()+1, unit.z()+1);
    }
    vec3 unit_direction = unit_vector(r.direction());
    t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

int main() {

    // Image

    const double aspect_ratio = 16.0/9.0;
    const int image_width = 800;
    const int image_height = int(image_width / aspect_ratio);

    // Camera

    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = point(0, 0, 0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);
;

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rLines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto u = double(i) / (image_width); // Horizontal vector
            auto v = double(j) / (image_height); // Vertical vector
            ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            color pixel_color = ray_color(r);
            
            print_color(std::cout, pixel_color);
        }
    }
    std::cerr << "\nDone.\n";
}