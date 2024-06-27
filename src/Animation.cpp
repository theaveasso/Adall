#include "Adall/Animation.hpp"

Animation::Animation() = default;

Animation::Animation(const std::string &name, const sf::Texture &t) {

}

Animation::Animation(const std::string &name, const sf::Texture &t, size_t frame_count, size_t speed) {

}

const std::string &Animation::get_name() const {
    return m_name;
}

const Vec2 &Animation::get_size() const {
    return m_size;
}

sf::Sprite &Animation::get_sprite() {
    return m_sprite;
}

void Animation::update() {
    m_current_frame += 1;

    // TODO
    // 1. calculate the correct frame of animation to play based on currentframe and speed
    // 2. set the texture rectangle properly (see contructor for simple)

}

bool Animation::has_ended() const {
    // TODO detect when animation has ended (last frame was played) and return value
    return false;
}






