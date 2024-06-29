#ifndef ADALL_INCLUDE_ADALL_ASSETS_HPP_
#define ADALL_INCLUDE_ADALL_ASSETS_HPP_

#include "Adall/Animation.hpp"

#include <string>

class Assets {
  Animation m_animation;
  std::string m_name{"Default"};

 public:
  Assets();

  void load_from_file(const std::string &path);

  Animation &get_animation(const std::string &name);
};

#endif //ADALL_INCLUDE_ADALL_ASSETS_HPP_