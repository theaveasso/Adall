#ifndef ADALL_INCLUDE_ADALL_SCENE_HPP_
#define ADALL_INCLUDE_ADALL_SCENE_HPP_

#include "Adall/Action.hpp"
#include "Adall/EntityManager.hpp"
#include "Adall/GameEngine.hpp"

#include <memory>

class GameEngine;
typedef std::map<int, std::string> ActionMap;

class Scene {
 protected:
  GameEngine *m_game;
  EntityManager m_entity_manager;
  ActionMap m_action_map;
  bool m_paused{false};
  bool m_has_ended{false};
  size_t m_current_frame{0};

  void set_paused(bool paused);

 public:
  explicit Scene(GameEngine *game_engine);
  Scene(GameEngine *game_engine, std::string &level);

  virtual void update() = 0;

  virtual void s_do_action(const Action &action) = 0;

  virtual void s_render() = 0;

  void do_action(const Action &action);

  void simulate(size_t frames);

  void register_action(int input_key, const std::string &action_name);

  [[nodiscard]] static size_t width();

  static size_t height();

  static size_t current_frame();

  static bool has_ended();

  [[nodiscard]] const ActionMap &get_action_map() const;

  void draw_line(const Vec2 &p1, const Vec2 &p2);
};

#endif //ADALL_INCLUDE_ADALL_SCENE_HPP_