#ifndef ADALL_INCLUDE_ADALL_ENTITY_HPP_
#define ADALL_INCLUDE_ADALL_ENTITY_HPP_

#include "Adall/Component.hpp"
#include <memory>
#include <tuple>

typedef std::tuple<CTransform, CLifespan, CInput, CBoundingBox, CAnimation, CGravity, CState> ComponentTuple;

class Entity {
 private:
  friend class EntityManager;

  bool active_{true};
  size_t id_{0};
  std::string tag_{"default"};

  ComponentTuple m_components;

  Entity(size_t id, const std::string &tag);

 public:
  void destroy();

  size_t id() const;

  bool is_active() const;

  const std::string &tag() const;

  template<typename T>
  bool has_component() const;

  template<typename T, typename... TArgs>
  T &add_component(TArgs &&... mArgs);

  template<typename T>
  T &get_component() const;

  template<typename T>
  T &remove_component() const;

  [[nodiscard]] const std::string &get_tag() const;

  [[nodiscard]] size_t get_id() const;
};

#endif //ADALL_INCLUDE_ADALL_ENTITY_HPP_