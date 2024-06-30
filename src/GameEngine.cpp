#include "Adall/GameEngine.hpp"
#include "Adall/Scene_Menu.hpp"

#include <iostream>
#include <utility>

GameEngine::GameEngine() = default;

void GameEngine::init(const std::string &path) {
    m_assets.load_from_file(path);

    m_window.create(sf::VideoMode(1280, 768), "Adall");
    m_window.setFramerateLimit(60);

    change_scene("MENU", std::make_shared<Scene_Menu>(this));
}

void GameEngine::run() {
    while (is_running()) {
        update();
    }
}

void GameEngine::update() {
    s_user_input();
    current_scene()->update();
    current_scene()->s_render();
}

void GameEngine::quit() {
    m_window.close();
}

void GameEngine::change_scene(const std::string &name, std::shared_ptr<Scene> scene) {
    m_current_scene = name;
    m_scenes[name] = scene;
}

void GameEngine::change_scene(const std::string &name, std::shared_ptr<Scene> scene, bool end_current_scene) {

}

void GameEngine::s_user_input() {
    sf::Event event{};
    while (m_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            quit();
        }

        if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
                case sf::Keyboard::X : {
                    sf::Texture texture;
                    texture.create(m_window.getSize().x, m_window.getSize().y);
                    texture.update(m_window);
                    if (texture.copyToImage().saveToFile("test.png")) {
                        std::cout << "screenshot saved to " << "test.png\n";
                    }
                    break;
                };
                default:break;
            }
        }

        if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
            if (current_scene()->get_action_map().find(event.key.code) == current_scene()->get_action_map().end()) {
                continue;
            }

            const std::string action_type = (event.type == sf::Event::KeyPressed) ? "START" : "END";

            current_scene()->s_do_action(Action(current_scene()->get_action_map().at(event.key.code), action_type));
        }

        if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseButtonReleased) {
            if (current_scene()->get_action_map().find(event.key.code) == current_scene()->get_action_map().end()) {
                continue;
            }

            const std::string action_type = (event.type == sf::Event::MouseButtonPressed) ? "START" : "END";

            current_scene()->s_do_action(Action(current_scene()->get_action_map().at(event.key.code), action_type));
        }

    }

}

std::shared_ptr<Scene> GameEngine::current_scene() {
    return m_scenes[m_current_scene];
}

bool GameEngine::is_running() const {
    return m_running && m_window.isOpen();
}

sf::RenderWindow &GameEngine::window() {
    return m_window;
}

Assets &GameEngine::assets() {
    return m_assets;
}

