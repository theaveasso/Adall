#ifndef ADALL_INCLUDE_ADALL_VEC2_HPP_
#define ADALL_INCLUDE_ADALL_VEC2_HPP_

class Vec2 {
 public:
  float x{0};

  float y{0};

  Vec2();

  Vec2(float x, float y);

  void operator-=(const Vec2 &rhs);

  void operator+=(const Vec2 &rhs);

  void operator*=(const Vec2 &rhs);

  void operator/=(const Vec2 &rhs);

  Vec2 operator+(const Vec2 &rhs) const;

  Vec2 operator-(const Vec2 &rhs) const;

  Vec2 operator*(const Vec2 &rhs) const;

  Vec2 operator/(const Vec2 &rhs) const;

  Vec2 operator*(float val) const;

  Vec2 operator/(float val) const;

  bool operator==(const Vec2 &rhs) const;

  bool operator!=(const Vec2 &rhs) const;

  [[nodiscard]] float length() const;

  [[nodiscard]] float distance(const Vec2 &rhs) const;

  void normalize();

  [[maybe_unused]] void dbg() const;

  Vec2 &add(const Vec2 &rhs);

  Vec2 &subtract(const Vec2 &rhs);

  Vec2 &scale(float val);

  Vec2 &norm();
};

#endif //ADALL_INCLUDE_ADALL_VEC2_HPP_