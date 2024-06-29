#ifndef ADALL_INCLUDE_ADALL_ENTITY_HPP_
#define ADALL_INCLUDE_ADALL_ENTITY_HPP_

#include "Adall/Component.hpp"
#include <tuple>

typedef std::tuple<CTransform, CLifespan, CInput, CBoundingBox, CAnimation, CGravity, CScore, CState> ComponentTuple;

class Entity {
 private:
  friend class EntityManager;

  bool m_active{true};
  size_t m_id{0};
  std::string m_tag{"default"};

  ComponentTuple m_components;

  Entity(size_t id, const std::string &tag);

 public:
  void destroy();

  [[nodiscard]] bool is_active();

  [[nodiscard]] size_t id() const;

  [[nodiscard]] const std::string &tag() const;

  template<typename T>
  [[nodiscard]] bool has_component() const;

  template<typename T, typename... TArgs>
  T &add_component(TArgs &&... mArgs);

  template<typename T>
  T &get_component();

  template<typename T>
  const T &get_component() const;

  template<typename T>
  void remove_component();
};

#endif //ADALL_INCLUDE_ADALL_ENTITY_HPP_