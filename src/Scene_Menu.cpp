#include "Adall/Scene_Menu.hpp"
#include "Adall/Scene_Play.hpp"

#include <memory>

Scene_Menu::Scene_Menu(GameEngine *game_engine)
    : Scene(game_engine) {
    init();
}

void Scene_Menu::init() {
    register_action(sf::Mouse::isButtonPressed(sf::Mouse::Left), "MOUSE_CLICK");

    m_title = "Adall Game <3";
    m_menu_strings = {
        "PLAY",
        "OPTIONS",
        "QUIT"
    };
}

void Scene_Menu::on_end() {
}

void Scene_Menu::s_do_action(const Action &action) {
    if (action.type() == "START") {
        if (action.name() == "MOUSE_CLICK") {
            auto mouse_pos{sf::Mouse::getPosition()};
            if (mouse_pos.y > 840 && mouse_pos.y < 880) {
                m_selected_menu_index = 1;
            }
        }
    }
}

void Scene_Menu::s_render() {
    m_game->window().clear();

    float start_y{10.0f}; // Starting y-coordinate
    float line_height{80.0f}; // Vertical spacing between menu items

    m_menu_text.setCharacterSize(64);
    m_menu_text.setFillColor(sf::Color::Yellow);
    m_menu_text.setFont(m_game->assets().get_font("PixelOperator8-Bold"));
    m_menu_text.setString(m_title);
    m_menu_text.setPosition(0, start_y);
    m_game->window().draw(m_menu_text);

    m_menu_text.setFillColor(sf::Color::White);
    m_menu_text.setFont(m_game->assets().get_font("PixelOperator8"));
    start_y += line_height;
    for (std::size_t i = 0; i < m_menu_strings.size(); i++) {
        m_menu_text.setString(m_menu_strings[i]);
        m_menu_text.setPosition(0, start_y + static_cast<float>(i) * line_height);

        m_game->window().draw(m_menu_text);
    }

    m_game->window().display();
}

void Scene_Menu::update() {
    if (m_selected_menu_index == 0)
        m_game->change_scene("PLAY", std::make_shared<Scene_Play>(this->m_game, "assets/levels/level_1.txt"));
    else if (m_selected_menu_index == 1)
        m_game->change_scene("PLAY", std::make_shared<Scene_Menu>(this->m_game));

}