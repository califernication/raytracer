#ifndef VEC3_UTILITY_H
#define VEC3_UTILITY_H

#include <cmath>
#include "vec3.h"

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
inline vec3 operator*(const vec3 &v, const double t) {
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

#endif