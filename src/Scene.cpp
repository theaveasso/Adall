#include "Adall/Scene.hpp"

Scene::Scene(GameEngine *game_engine) : m_game(game_engine) {
}

void Scene::set_paused(bool paused) {
    m_paused = paused;
}

void Scene::simulate(const size_t frames) {}

void Scene::register_action(int input_key, const std::string &action_name) {
    m_action_map[input_key] = action_name;
}

size_t Scene::width() { return 0; }

size_t Scene::height() { return 0; }

size_t Scene::current_frame() {
    return 0;
}

bool Scene::has_ended() {
    return false;
}

const ActionMap &Scene::get_action_map() const {
    return m_action_map;
}

void Scene::draw_line(const Vec2 &p1, const Vec2 &p2) {

}

void Scene::do_action(const Action &action) {

}