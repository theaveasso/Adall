#include <SFML/Graphics.hpp>

#include "Adall/Scene_Play.hpp"
#include "Adall/Entity.hpp"
#include "Adall/Component.hpp"

Scene_Play::Scene_Play(GameEngine *game_engine, std::string &level_path)
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

void Scene_Play::load_level(const std::string &level_path) {
    m_entity_manager = EntityManager();

    spawn_player();

    auto brick = m_entity_manager.add_entity("tile");
    brick->add_component<CAnimation>(m_game->assets().get_animation("Brick"), true);
    brick->add_component<CTransform>(Vec2(96, 480));

    auto block = m_entity_manager.add_entity("tile");
    block->add_component<CAnimation>(m_game->assets().get_animation("Block"), true);
    block->add_component<CTransform>(Vec2(224, 480));
    block->add_component<CBoundingBox>(m_game->assets().get_animation("Block").get_size());
}

void Scene_Play::on_end() {}

void Scene_Play::update() {
    m_entity_manager.update();

    s_movement();
    s_lifespan();
    s_collision();
    s_animation();
    s_render();
}

Vec2 Scene_Play::grid_to_mid_pixel(float grid_x, float grid_y, const std::shared_ptr<Entity> &entity) {
    return {entity->get_component<CTransform>().pos.x, entity->get_component<CTransform>().pos.y};
}

void Scene_Play::spawn_player() {
    m_player = m_entity_manager.add_entity("player");
    m_player->add_component<CAnimation>(m_game->assets().get_animation("Stand"), true);
    m_player->add_component<CTransform>(Vec2(224, 352));
    m_player->add_component<CBoundingBox>(m_game->assets().get_animation("Stand").get_size());
}

void Scene_Play::spawn_bullet() {
    // TODO spawn a bullet
}

// SYSTEMS
void Scene_Play::s_movement() {

}

void Scene_Play::s_lifespan() {

}

void Scene_Play::s_collision() {

}

void Scene_Play::s_animation() {

}

void Scene_Play::s_render() {

}

void Scene_Play::s_do_action(const Action &action) {
    if (action.type() == "START") {
        if (action.name() == "TOGGLE_TEXTURE") m_draw_textures = !m_draw_textures;
        else if (action.name() == "TOGGLE_COLLISION") m_draw_collision = !m_draw_collision;
        else if (action.name() == "TOGGLE_GRID") m_draw_collision = !m_draw_grid;
        else if (action.name() == "PAUSE") set_paused(!m_paused);
        else if (action.name() == "QUIT") on_end();
    } else if (action.type() == "END") {

    }
}