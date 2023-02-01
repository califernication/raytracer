#pragma once
#include <cmath>
#include <iostream>

class Vec3 {
    public:
        // Constructor with list initialization
        Vec3() : e{0,0,0} {}
        Vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

        // Getters. In xyz and rgb forms for readability
        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        double r() const { return e[0]; }
        double g() const { return e[1]; }
        double b() const { return e[2]; }

        Vec3 operator-() const { return Vec3(-e[0], -e[1], -e[2]); }
        double operator[](int i) const { return e[i]; }
        double& operator[](int i) { return e[i]; }

        // TODO: Consider overloading simple +, -, *, / operators in the future.

        Vec3& operator+=(const Vec3 &v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        Vec3& operator-=(const Vec3 &v) {
            e[0] -= v.e[0];
            e[1] -= v.e[1];
            e[2] -= v.e[2];
            return *this;
        }

        Vec3& operator*=(const double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        Vec3& operator/=(const double t) {
            return *this *= 1/t;
        }

        double length() const {
            return std::sqrt(length_squared());
        }

        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

    //TODO: this should be private
    public:
        double e[3];
};

// Sout
inline std::ostream& operator<<(std::ostream &out, const Vec3 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// Vector addition
inline Vec3 operator+(const Vec3 &v, const Vec3 &v1) {
    return Vec3(v.e[0] + v1.e[0], v.e[1] + v1.e[1], v.e[2] + v1.e[2]);
}

// Vector substraction
inline Vec3 operator-(const Vec3 &v, const Vec3 &v1) {
    return Vec3(v.e[0] - v1.e[0], v.e[1] - v1.e[1], v.e[2] - v1.e[2]);
}

// Vector multiplication
inline Vec3 operator*(const Vec3 &v, const Vec3 &v1) {
    return Vec3(v.e[0]*v1.e[0], v.e[1]*v1.e[1], v.e[2]*v1.e[2]);
}

// Vector-num multiplication
inline Vec3 operator*(const double t, const Vec3 &v) {
    return Vec3(v.e[0]*t, v.e[1]*t, v.e[2]*t);
}

// (free-func) Vector-num multiplication
inline Vec3 operator*(const Vec3 &v, const double t) {
    return Vec3(v.e[0]*t, v.e[1]*t, v.e[2]*t);
}

// Vector-num division
inline Vec3 operator/(Vec3 v, double t) {
    return (1/t) * v;
}

// Vector dot product
inline double dot(const Vec3 &v, const Vec3 &v1) {
    return v.e[0] * v1.e[0]
         + v.e[1] * v1.e[1]
         + v.e[2] * v1.e[2];
}

// Vector cross product
inline Vec3 cross(const Vec3 &v, const Vec3 &v1) {
    return Vec3(v.e[1] * v1.e[2] - v.e[2] * v1.e[1],
                v.e[2] * v1.e[0] - v.e[0] * v1.e[2],
                v.e[0] * v1.e[1] - v.e[1] * v1.e[0]);
}

// Create unit vector
inline Vec3 getUnitVector(Vec3 v) {
    return v / v.length();
}

using Point = Vec3;   // 3D point
using Color = Vec3;   // RGB color
using Direction = Vec3; // direction vector