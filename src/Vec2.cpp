#include <cmath>
#include <iostream>
#include "Adall/Vec2.hpp"

Vec2::Vec2() = default;

Vec2::Vec2(float x, float y) : x(x), y(y) {}

void Vec2::operator-=(const Vec2 &rhs) {
    x -= rhs.x;
    y -= rhs.y;
}

void Vec2::operator+=(const Vec2 &rhs) {
    x += rhs.x;
    y += rhs.y;
}

void Vec2::operator*=(const Vec2 &rhs) {
    x *= rhs.x;
    y *= rhs.y;
}

void Vec2::operator/=(const Vec2 &rhs) {
    x /= rhs.x;
    y /= rhs.y;
}

void Vec2::dbg() const {
    std::cout << "x : " << x << " " << "y : " << y << std::endl;
}

Vec2 Vec2::operator+(const Vec2 &rhs) const {
    return Vec2{x + rhs.x, y + rhs.y};
}

Vec2 Vec2::operator-(const Vec2 &rhs) const {
    return Vec2{x - rhs.x, y - rhs.y};
}

Vec2 Vec2::operator*(const Vec2 &rhs) const {
    return Vec2{x * rhs.x, y * rhs.y};
}

Vec2 Vec2::operator/(const Vec2 &rhs) const {
    return Vec2{x / rhs.x, y / rhs.y};
}

Vec2 Vec2::operator*(float val) const {
    return Vec2{x * val, y * val};
}

Vec2 Vec2::operator/(float val) const {
    return Vec2{x / val, y / val};
}

bool Vec2::operator==(const Vec2 &rhs) const {
    return x == rhs.x && y == rhs.y;
}

bool Vec2::operator!=(const Vec2 &rhs) const {
    return x != rhs.x || y != rhs.y;
}

float Vec2::length() const {
    return std::sqrt(x * x + y * y);
}

float Vec2::distance(const Vec2 &rhs) const {
    float dx = x - rhs.x;
    float dy = y - rhs.y;
    return std::sqrt(dx * dx + dy * dy);
}

void Vec2::normalize() {
    float magnitude = this->length();
    if (magnitude > 0) {
        x /= magnitude;
        y /= magnitude;
    }
}

Vec2 &Vec2::add(const Vec2 &rhs) {
    x += rhs.x;
    y += rhs.y;
    return *this;
}

Vec2 &Vec2::subtract(const Vec2 &rhs) {
    x -= rhs.x, y -= rhs.y;
    return *this;
}

Vec2 &Vec2::scale(float val) {
    x *= val, y *= val;
    return *this;
}

Vec2 &Vec2::norm() {
    normalize();
    return *this;
}
