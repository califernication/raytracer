#include <iostream>

#include "Color.h"
#include "Vec3.h"
#include "Ray.h"

double hitSphere(const Point& center, double radius, const Ray& r) {
    Vec3 oc = r.origin() - center;
    auto a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_squared() - radius*radius;
    auto discriminant = half_b*half_b - a*c;

    if (discriminant < 0) { // Check if negative root
        return -1.0;
    } else {
        return (-half_b - std::sqrt(discriminant) ) / a; // else retun the value
    }
}


Color rayColor(const Ray& r) {
    double t = hitSphere(Point(0,0,-1), 0.5, r);
    if (t > 0.0) {
        Vec3 unit = getUnitVector(r.at(t) - Vec3(0,0,-1));
        return 0.5*Color(unit.x()+1, unit.y()+1, unit.z()+1);
    }
    Vec3 unitDirection = getUnitVector(r.direction());
    t = 0.5*(unitDirection.y() + 1.0);
    return (1.0-t)*Color(1.0, 1.0, 1.0) + t*Color(0.5, 0.7, 1.0);
}

int main() {

    // Image

    const double aspectRatio = 16.0/9.0;
    const int imageWidth = 800;
    const int imageHeight = int(imageWidth / aspectRatio);

    // Camera

    auto viewportHeight = 2.0;
    auto viewportWidth = aspectRatio * viewportHeight;
    auto focalLength = 1.0;

    auto origin = Point(0, 0, 0);
    auto horizontal = Vec3(viewportWidth, 0, 0);
    auto vertical = Vec3(0, viewportHeight, 0);
    auto lowerLeftCorner = origin - horizontal/2 - vertical/2 - Vec3(0, 0, focalLength);
;

    // Render

    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

    for (int j = imageHeight-1; j >= 0; --j) {
        std::cerr << "\rLines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < imageWidth; ++i) {
            auto u = double(i) / (imageWidth); // Horizontal vector
            auto v = double(j) / (imageHeight); // Vertical vector
            Ray r(origin, lowerLeftCorner + u*horizontal + v*vertical - origin);
            Color pixel_color = rayColor(r);
            
            printColor(std::cout, pixel_color);
        }
    }
    std::cerr << "\nDone.\n";
}