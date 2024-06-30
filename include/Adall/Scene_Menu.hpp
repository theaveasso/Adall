#ifndef ADALL_INCLUDE_ADALL_SCENE_MENU_HPP_
#define ADALL_INCLUDE_ADALL_SCENE_MENU_HPP_

#include <SFML/Graphics.hpp>

#include "Adall/Scene.hpp"
#include "EntityManager.hpp"

#include <vector>
#include <memory>

class Scene_Menu : public Scene {
 public:
  explicit Scene_Menu(GameEngine *game_engine);

  void on_end();

 protected:
  std::string m_title;
  std::vector<std::string> m_menu_strings;

  sf::Text m_menu_text;
  size_t m_selected_menu_index{0};

  void init();
  void update();

  void s_render();
  void s_do_action(const Action &action);

};

#endif //ADALL_INCLUDE_ADALL_SCENE_MENU_HPP_