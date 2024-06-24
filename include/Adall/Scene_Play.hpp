#ifndef ADALL_INCLUDE_ADALL_SCENE_PLAY_HPP_
#define ADALL_INCLUDE_ADALL_SCENE_PLAY_HPP_

#include "Adall/Scene.hpp"

class Scene_Play : public Scene {
  struct PlayerConfig {
    float X, Y, CX, CY, SPEED, MAXSPEED, JUMP, GRAVITY;
    std::string WEAPON;
  };

 protected:
  std::shared_ptr<Entity> m_player;
  std::string m_level_path;
  PlayerConfig m_player_config;
  bool m_draw_textures{true};
  bool m_draw_collision{false};
  bool m_draw_grid{false};
  const Vec2 m_grid_size{64, 64};
  sf::Text m_grid_text;

  void init(const std::string &level_path);

  void update() override;

  void s_do_action(const Action &action) override;

  void s_render();

  void on_end();

  void load_level(const std::string &level_path);

 public:
  Scene_Play(GameEngine *game_engine, std::string level_path);
};

#endif //ADALL_INCLUDE_ADALL_SCENE_PLAY_HPP_