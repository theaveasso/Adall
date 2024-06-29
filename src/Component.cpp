#include "Adall/Component.hpp"
#include <SFML/Graphics.hpp>

CTransform::CTransform() = default;

CTransform::CTransform(const Vec2 &p) {}

CTransform::CTransform(const Vec2 &position,
                       const Vec2 &velocity,
                       float angle) : pos(position),
                                      velocity(velocity),
                                      angle(angle) {}

CShape::CShape(float radius,
               int points,
               const sf::Color &fill,
               const sf::Color &outline,
               float thickness) /*: circle(radius, points)*/ {
    sf::FloatRect circle_bounds = circle.getLocalBounds();
    circle.setOrigin(circle_bounds.width / 2, circle_bounds.height / 2);
    circle.setFillColor(fill);
    circle.setOutlineColor(outline);
    circle.setOutlineThickness(thickness);
}

CCollision::CCollision(float r) : radius(r) {}

CScore::CScore(int s) : score(s) {};

CLifespan::CLifespan(int t) : remaining(t), total(t) {}

CInput::CInput() = default;

CBoundingBox::CBoundingBox(const Vec2 &s) : size(s), half_size(s.x / 2, s.y / 2) {}

CAnimation::CAnimation() = default;

CAnimation::CAnimation(Animation &animation, bool active) : m_animation(animation), m_active(active) {}