#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Adall/Vec2.hpp"
#include <SFML/Graphics.hpp>

class Component {

};

class CTransform : public Component {
 public:
  Vec2 pos{0.0f, 0.0f};
  Vec2 prev_pos{0.0f, 0.0f};
  Vec2 scale{1.0, 1.0};
  Vec2 velocity{0.0f, 0.0f};

  float angle = 0;

  CTransform();

  explicit CTransform(const Vec2 &p);

  CTransform(const Vec2 &position, const Vec2 &velocity, float angle);
};

class CShape {
 public:
  sf::CircleShape circle;

  CShape(float radius,
         int points,
         const sf::Color &fill,
         const sf::Color &outline,
         float thickness);
};

class CCollision {
 public:
  float radius{0};

  explicit CCollision(float r);
};

class CInput {
 public:
  bool up{false};
  bool down{false};
  bool right{false};
  bool left{false};
  bool shoot{false};

  CInput();
};

class CScore {
 public:
  int score{0};

  explicit CScore(int s);
};

class CLifespan {
 public:
  int remaining{0};
  int total{0};

  explicit CLifespan(int t);
};

class CBoundingBox : public Component {
 public:
  Vec2 size;
  Vec2 half_size;

  explicit CBoundingBox(const Vec2 &s);
};

class CAnimation {};

class CGravity {};

class CState {};

#endif // COMPONENT_HPP