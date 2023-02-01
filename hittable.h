#pragma once
#include "Ray.h"

struct HitRecord {
    Point p;
    Vec3 normal;
    double t;
};

class Hittable {
    public:
        virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const = 0;
};