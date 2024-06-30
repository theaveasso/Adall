#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include <SFML/Graphics.hpp>

#include "Adall/Scene.hpp"
#include "Adall/Assets.hpp"

#include <memory>
#include <map>
#include <string>

class Scene;

typedef std::map<std::string, std::shared_ptr<Scene>> SceneMap;

class GameEngine {
 public:
  GameEngine();

  void init(const std::string &path);
  void run();
  void update();
  void quit();

  std::shared_ptr<Scene> current_scene();

  void change_scene(const std::string &name, std::shared_ptr<Scene> scene);
  void change_scene(const std::string &name, std::shared_ptr<Scene> scene, bool end_current_scene);
  void s_user_input();

  Assets &assets();

  sf::RenderWindow &window();

  bool is_running() const;

 private:
  Assets m_assets;
  sf::RenderWindow m_window;
  bool m_running{true};
  std::string m_current_scene{"MENU"};

  SceneMap m_scenes;
};

#endif // GAME_ENGINE_HPP