#ifndef GAME_ENGINE_HPP
#define GAME_ENGINE_HPP

#include "Adall/Scene.hpp"

#include <memory>
#include <map>

class Scene;

class GameEngine {
 public:
  GameEngine(const std::string &path);

  void init(const std::string &path);

  std::shared_ptr<Scene> current_scene();
};

#endif // GAME_ENGINE_HPP