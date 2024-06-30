#include "Adall/Assets.hpp"

#include <iostream>
#include <vector>

Assets::Assets() = default;

void Assets::load_from_file(const std::string &path) {
    std::string path_sprites{path + "sprites/"};
    std::string path_sounds{path + "sounds/"};
    std::string path_music{path + "music/"};
    std::string path_fonts{path + "fonts/"};

    std::vector<std::string> fonts{
        "PixelOperator8",
        "PixelOperator8-Bold"
    };

    std::vector<std::string> sounds{
        "coin",
        "explosion",
        "hurt",
        "jump",
        "power_up",
        "tap"
    };

    std::vector<std::string> sprites{
        "coin",
        "fruit",
        "knight",
        "platforms",
        "slime_green",
        "slime_purple",
        "world_tileset",
    };

    load_fonts(path_fonts, fonts);
    load_sounds(path_sounds, sounds);
    load_sprites(path_sprites, sprites);

};

void Assets::add_texture(const std::string &name, const std::string &path) {

};

void Assets::add_animation(const std::string &name, Animation animation) {

};

void Assets::add_sound(const std::string &name, const std::string &path) {

};

void Assets::add_font(const std::string &name, const std::string &path) {

};

sf::Texture &Assets::get_texture(const std::string &name) {
    return m_textures[name];

};

Animation &Assets::get_animation(const std::string &name) {
    return m_animations[name];
};

sf::SoundBuffer &Assets::get_sound(const std::string &name) {
    return m_sounds[name];
};

sf::Font &Assets::get_font(const std::string &name) {
    return m_fonts[name];
};

void Assets::load_fonts(const std::string &path, const std::vector<std::string> &vec_fonts) {
    for (const auto &file : vec_fonts) {
        sf::Font font;
        std::string filepath = path + file + ".ttf";
        if (font.loadFromFile("assets/fonts/PixelOperator8.ttf")) m_fonts[file] = font;

    }
}

void Assets::load_sounds(const std::string &path, const std::vector<std::string> &vec_sounds) {
    for (const auto &file : vec_sounds) {
        sf::SoundBuffer sound;
        std::string filepath = path + file + ".wav";
        if (!sound.loadFromFile(filepath)) m_sounds[file] = sound;
    }

}

void Assets::load_sprites(const std::string &path, const std::vector<std::string> &vec_sprites) {
    for (const auto &file : vec_sprites) {
        sf::Texture texture;
        std::string filepath = path + file + ".png";
        if (texture.loadFromFile(filepath)) m_textures[file] = texture;
    }
}