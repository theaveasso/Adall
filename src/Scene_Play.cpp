#include "Adall/Scene_Play.hpp"

#include <SFML/Graphics.hpp>
#include <utility>

Scene_Play::Scene_Play(GameEngine *game_engine, std::string level_path)
    : Scene(game_engine), m_level_path(level_path) {
    init(m_level_path);
}

void Scene_Play::init(const std::string &level_path) {
    register_action(sf::Keyboard::Escape, "QUIT");
    register_action(sf::Keyboard::P, "PAUSED");
    register_action(sf::Keyboard::T, "TOGGLE_TEXTURE");
    register_action(sf::Keyboard::C, "TOGGLE_COLLISION");
    register_action(sf::Keyboard::G, "TOGGLE_GRID");

    // TODO register all other gameplay actions

    m_grid_text.setCharacterSize(12);
    // m_grid_text.setFont("sd.ttf");

    load_level(level_path);

}

void Scene_Play::load_level(const std::string &level_path) {}

void Scene_Play::on_end() {}

void Scene_Play::update() {}

void Scene_Play::s_do_action(const Action &action) {}

void Scene_Play::s_render() {}