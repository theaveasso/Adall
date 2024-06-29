#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include "Adall/Vec2.hpp"
#include "Adall/Animation.hpp"

#include <SFML/Graphics.hpp>

class Component {

};

class CTransform : public Component {
 public:
  bool has{false};
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
  bool has{false};
  sf::CircleShape circle;

  CShape(float radius,
         int points,
         const sf::Color &fill,
         const sf::Color &outline,
         float thickness);
};

class CCollision {
 public:
  bool has{false};
  float radius{0};

  explicit CCollision(float r);
};

class CInput {
 public:
  bool has{false};
  bool up{false};
  bool down{false};
  bool right{false};
  bool left{false};
  bool shoot{false};

  CInput();
};

class CScore {
 public:
  bool has{false};
  int score{0};

  CScore() = default;
  explicit CScore(int s);
};

class CLifespan {
 public:
  bool has{false};
  int remaining{0};
  int total{0};

  CLifespan() = default;
  explicit CLifespan(int t);
};

class CBoundingBox : public Component {
 public:
  bool has{false};
  Vec2 size;
  Vec2 half_size;

  CBoundingBox() = default;
  explicit CBoundingBox(const Vec2 &s);
};

class CAnimation {
 private:
  std::string m_name;
  bool m_active{};
  Animation m_animation;

 public:
  bool has{false};

  CAnimation();

  explicit CAnimation(Animation &animation, bool active);
};

class CGravity {
 public:
  bool has{false};
  CGravity() = default;
};

class CState {
 public:
  bool has{false};
  CState() = default;
};

#endif // COMPONENT_HPP