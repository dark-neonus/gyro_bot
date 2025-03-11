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
    float dot(const Vec3& v) const {
        return x * v.x + y * v.y + z * v.z;
    }

    // Cross product (if needed for certain 3D operations)
    Vec3 cross(const Vec3& v) const {
        return Vec3(
            y * v.z - z * v.y,
            z * v.x - x * v.z,
            x * v.y - y * v.x
        );
    }

    float length() const {
      return std::sqrt(x * x + y * y + z * z);
    }

    // Normalize the vector (make its length = 1)
    Vec3 normalize() const {
        float v_len = length();
        return Vec3(x / v_len, y / v_len, z / v_len);
    }

    static Vec3 get_perpendicular(Vec3 v1, Vec3 v2) {
      return v1.cross(v2).normalize();
    }

    static Vec3 rotateAroundAxis(Vec3 p, Vec3 axis, double theta) {
      Vec3 k = axis.normalize();  // Ensure axis is a unit vector
      Vec3 p_rotated = 
          p * std::cos(theta) +
          k.cross(p) * std::sin(theta) +
          k * (k.dot(p) * (1 - std::cos(theta)));
      return p_rotated;
    }
};


#endif