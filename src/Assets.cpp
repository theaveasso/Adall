#include "Adall/Assets.hpp"

Assets::Assets() = default;

void Assets::load_from_file(const std::string &path) {

}

Animation &Assets::get_animation(const std::string &name) {
    return m_animation;
}