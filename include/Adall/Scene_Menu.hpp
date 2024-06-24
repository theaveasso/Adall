//
// Created by thebo on 6/23/2024.
//

#ifndef ADALL_INCLUDE_ADALL_SCENE_MENU_HPP_
#define ADALL_INCLUDE_ADALL_SCENE_MENU_HPP_

#include "Adall/Scene.hpp"
#include "EntityManager.hpp"
#include <SFML/Graphics.hpp>

#include <map>
#include <vector>
#include <memory>
#include <deque>

class Scene_Menu : public Scene {
 protected:
  std::string m_title;
  std::vector<std::string> m_menu_strings;
  std::vector<std::string> m_level_paths;

  sf::Text m_menu_text;
  size_t m_selected_menu_index{0};

  void init();

  void update();

  void on_end();

  void s_do_action(const Action &action);

 public:
  Scene_Menu(GameEngine *game_engine = nullptr);

  void s_render();

};

#endif //ADALL_INCLUDE_ADALL_SCENE_MENU_HPP_