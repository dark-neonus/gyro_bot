#pragma once

#include <cmath>
#ifndef VEC_3_H_
#define VEC_3_H_
// #include "../Vec2.h"

// class CoordinateSystem;
// class Plane;
// class Vec2;

class Vec3 {
public:
    float x, y, z;

    // Constructor
    Vec3(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    // Vector addition
    Vec3 operator + (const Vec3& v) {
        return Vec3(x + v.x, y + v.y, z + v.z);
    }

    // Vector subtraction
    Vec3 operator - (const Vec3& v) {
        return Vec3(x - v.x, y - v.y, z - v.z);
    }

    // Vector multiplication
    Vec3 operator * (const Vec3& v) {
        return Vec3(x * v.x, y * v.y, z * v.z);
    }

    // Vector multiplication
    Vec3 operator * (float scalar) {
        return Vec3(x * scalar, y * scalar, z * scalar);
    }

    // Vector divizion
    Vec3 operator / (const Vec3& v) {
        return Vec3(x / v.x, y / v.y, z / v.z);
    }

    // Vector divizion
    Vec3 operator / (float scalar) {
        return Vec3(x / scalar, y / scalar, z / scalar);
    }

    // Dot product
    float dot(const Vec3& v) {
        return x * v.x + y * v.y + z * v.z;
    }

    // Cross product (if needed for certain 3D operations)
    Vec3 cross(const Vec3& v) {
        return Vec3(
            y * v.z - z * v.y,
            z * v.x - x * v.z,
            x * v.y - y * v.x
        );
    }

    // Normalize the vector (make its length = 1)
    Vec3 normalize() {
        float length = std::sqrt(x * x + y * y + z * z);
        return Vec3(x / length, y / length, z / length);
    }

    static Vec3 get_perpendicular(Vec3 v1, Vec3 v2) {
      return v1.cross(v2).normalize();
    }
};

#endif