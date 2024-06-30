#ifndef ADALL_INCLUDE_ADALL_SCENE_PLAY_HPP_
#define ADALL_INCLUDE_ADALL_SCENE_PLAY_HPP_

#include "Adall/Scene.hpp"

class Scene_Play : public Scene {
 public:
  explicit Scene_Play(GameEngine *game_engine, std::string &level_path);

 protected:
  struct PlayerConfig {
    float X, Y, CX, CY, SPEED, MAXSPEED, JUMP, GRAVITY;
    std::string WEAPON;
  };

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
  void on_end();

  void s_do_action(const Action &action) override;
  void s_render() override;
  void s_animation();
  void s_movement();
  void s_enemy_spawner();
  void s_collision();
  void s_debug();
  void s_lifespan();

  void spawn_player();
  void spawn_bullet();

  void load_level(const std::string &level_path);

  static Vec2 grid_to_mid_pixel(float grid_x, float grid_y, const std::shared_ptr<Entity> &entity);
};

#endif //ADALL_INCLUDE_ADALL_SCENE_PLAY_HPP_