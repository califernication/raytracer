#pragma once
#include <Hittable.h>
#include <Vec3.h>

class Sphere : public Hittable {
    public:
        Sphere() {}
        Sphere(Point cen, double r) : center(cen), radius(r) {};

        virtual bool hit(const Ray& r, double t_min, double t_max, HitRecord& rec) const override;

    public:
        Point center;
        double radius;
};