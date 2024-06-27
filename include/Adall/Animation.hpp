#ifndef ADALL_INCLUDE_ADALL_ANIMATION_HPP_
#define ADALL_INCLUDE_ADALL_ANIMATION_HPP_

#include <SFML/Graphics.hpp>

#include "Adall/Vec2.hpp"

#include <string>

class Animation {
 private:
  sf::Sprite  m_sprite;
  size_t      m_frame_count{1};
  size_t      m_current_frame{0};
  size_t      m_speed{0};
  Vec2        m_size{1, 1};
  std::string m_name{"none"};

 public:
  Animation();

  Animation(const std::string &name, const sf::Texture &t);

  Animation(const std::string &name, const sf::Texture &t, size_t frame_count, size_t speed);

  const std::string &get_name() const;

  const Vec2 &get_size() const;

  sf::Sprite &get_sprite();

  void update();

  bool has_ended() const;
};
#endif //ADALL_INCLUDE_ADALL_ANIMATION_HPP_