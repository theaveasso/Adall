#ifndef ADALL_INCLUDE_ADALL_ASSETS_HPP_
#define ADALL_INCLUDE_ADALL_ASSETS_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Adall/Animation.hpp"

#include <string>
#include <map>

typedef std::map<std::string, sf::Font> FontMap;
typedef std::map<std::string, sf::Music> MusicMap;
typedef std::map<std::string, sf::SoundBuffer> SoundMap;
typedef std::map<std::string, sf::Texture> TextureMap;
typedef std::map<std::string, Animation> AnimationMap;

class Assets {
 public:
  Assets();

  void load_from_file(const std::string &path);

  void add_texture(const std::string &name, const std::string &path);
  void add_animation(const std::string &name, Animation animation);
  void add_sound(const std::string &name, const std::string &path);
  void add_font(const std::string &name, const std::string &path);

  sf::Texture &get_texture(const std::string &name);
  Animation &get_animation(const std::string &name);
  sf::SoundBuffer &get_sound(const std::string &name);
  sf::Font &get_font(const std::string &name);

 private:
  FontMap m_fonts;
  SoundMap m_sounds;
  MusicMap m_musics;
  TextureMap m_textures;
  AnimationMap m_animations;

  void load_fonts(const std::string &path, const std::vector<std::string> &vec_fonts);
  void load_sounds(const std::string &path, const std::vector<std::string> &vec_sounds);
  void load_sprites(const std::string &path, const std::vector<std::string> &vec_sprites);
};

#endif //ADALL_INCLUDE_ADALL_ASSETS_HPP_