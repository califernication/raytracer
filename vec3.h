#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
    public:
        // Constructor with list initialization
        vec3() : e{0,0,0} {}
        vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

        // Getters. In xyz and rgb forms for readability
        double x() const { return e[0]; }
        double y() const { return e[1]; }
        double z() const { return e[2]; }

        double r() const { return e[0]; }
        double g() const { return e[1]; }
        double b() const { return e[2]; }

        vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
        double operator[](int i) const { return e[i]; }
        double& operator[](int i) { return e[i]; }

        // Consider overloading simple +, -, *, / operators in the future.

        vec3& operator+=(const vec3 &v) {
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this;
        }

        vec3& operator-=(const vec3 &v) {
            e[0] -= v.e[0];
            e[1] -= v.e[1];
            e[2] -= v.e[2];
            return *this;
        }

        vec3& operator*=(const double t) {
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this;
        }

        vec3& operator/=(const double t) {
            return *this *= 1/t;
        }

        double length() const {
            return sqrt(length_squared());
        }

        double length_squared() const {
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }

    public:
        double e[3];
};

// Type aliases for vec3
using point3 = vec3;   // 3D point
using color = vec3;    // RGB color

#endif

// Utility Functions

// Sout
inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

// Vector addition
inline vec3 operator+(const vec3 &v, const vec3 &v1) {
    return vec3(v.e[0] + v1.e[0], v.e[1] + v1.e[1], v.e[2] + v1.e[2]);
}

// Vector substraction
inline vec3 operator-(const vec3 &v, const vec3 &v1) {
    return vec3(v.e[0] - v1.e[0], v.e[1] - v1.e[1], v.e[2] - v1.e[2]);
}

// Vector multiplication
inline vec3 operator*(const vec3 &v, const vec3 &v1) {
    return vec3(v.e[0]*v1.e[0], v.e[1]*v1.e[1], v.e[2]*v1.e[2]);
}

// Vector-num multiplication
inline vec3 operator*(const double t, const vec3 &v) {
    return vec3(v.e[0]*t, v.e[1]*t, v.e[2]*t);
}

// (free-func) Vector-num multiplication
inline vec3 operator*(const double t, const vec3 &v) {
    return vec3(v.e[0]*t, v.e[1]*t, v.e[2]*t);
}

// Vector-num division
inline vec3 operator/(vec3 v, double t) {
    return (1/t) * v;
}

// Vector dot product
inline double dot(const vec3 &v, const vec3 &v1) {
    return v.e[0] * v1.e[0]
         + v.e[1] * v1.e[1]
         + v.e[2] * v1.e[2];
}

// Vector cross product
inline vec3 cross(const vec3 &v, const vec3 &v1) {
    return vec3(v.e[1] * v1.e[2] - v.e[2] * v1.e[1],
                v.e[2] * v1.e[0] - v.e[0] * v1.e[2],
                v.e[0] * v1.e[1] - v.e[1] * v1.e[0]);
}

// Create unit vector
inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}
