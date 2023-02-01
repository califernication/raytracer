#pragma once
#include "Vec3.h"

class Ray {
    public:
        // Constructor: P(t) = A + t*B
        Ray() {}
        Ray(const Point& origin, const Vec3& direction) : origin_(origin), direction_(direction) {}

        Point origin() const  { return origin_; }
        Vec3 direction() const { return direction_; }

        Point at(double t) const {
            return origin_ + (t * direction_);
        }

    private:
        Point origin_;
        Vec3 direction_;
};