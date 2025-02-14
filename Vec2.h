#pragma once

class Vec2 {
public:
    float x = 0.0f;
    float y = 0.0f;

    // Default constructor
    Vec2() = default;

    // Parameterized constructor
    Vec2(float x, float y) : x(x), y(y) {}

    // Addition
    Vec2 operator+(const Vec2& other) const {
        return Vec2(x + other.x, y + other.y);
    }

    // Subtraction
    Vec2 operator-(const Vec2& other) const {
        return Vec2(x - other.x, y - other.y);
    }

    // Multiplication by scalar (Vec2 * scalar)
    Vec2 operator*(float scalar) const {
        return Vec2(x * scalar, y * scalar);
    }

    // Division by scalar (Vec2 / scalar)
    Vec2 operator/(float scalar) const {
        return Vec2(x / scalar, y / scalar);
    }

    // Compound assignment operators
    Vec2& operator+=(const Vec2& other) {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vec2& operator-=(const Vec2& other) {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vec2& operator*=(float scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vec2& operator/=(float scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    // Unary negation (-Vec2)
    Vec2 operator-() const {
        return Vec2(-x, -y);
    }

    // Dot product
    float dot(const Vec2& other) const {
        return x * other.x + y * other.y;
    }

    // Magnitude (length)
    float length() const {
        return std::sqrt(x * x + y * y);
    }

    // Normalize (convert to unit vector)
    Vec2 normalized() const {
        float len = length();
        return (len > 0) ? *this / len : Vec2(0, 0);
    }

    // Equality check
    bool operator==(const Vec2& other) const {
        return x == other.x && y == other.y;
    }

    // Inequality check
    bool operator!=(const Vec2& other) const {
        return !(*this == other);
    }
};

// Multiplication by scalar on the left (scalar * Vec2)
inline Vec2 operator*(float scalar, const Vec2& vec) {
    return Vec2(vec.x * scalar, vec.y * scalar);
}

// Division by scalar on the left (for consistency)
inline Vec2 operator/(float scalar, const Vec2& vec) {
    return Vec2(scalar / vec.x, scalar / vec.y);
}

// Addition by scalar (Vec2 + scalar)
inline Vec2 operator+(const Vec2& vec, float scalar) {
    return Vec2(vec.x + scalar, vec.y + scalar);
}

// Addition by scalar (scalar + Vec2)
inline Vec2 operator+(float scalar, const Vec2& vec) {
    return Vec2(vec.x + scalar, vec.y + scalar);
}

// Subtraction by scalar (Vec2 - scalar)
inline Vec2 operator-(const Vec2& vec, float scalar) {
    return Vec2(vec.x - scalar, vec.y - scalar);
}

// Subtraction by scalar (scalar - Vec2)
inline Vec2 operator-(float scalar, const Vec2& vec) {
    return Vec2(scalar - vec.x, scalar - vec.y);
}