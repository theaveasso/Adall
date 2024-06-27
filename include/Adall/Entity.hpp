#ifndef ADALL_INCLUDE_ADALL_ENTITY_HPP_
#define ADALL_INCLUDE_ADALL_ENTITY_HPP_

#include "Adall/Component.hpp"
#include <tuple>


typedef std::tuple<CTransform, CLifespan, CInput, CBoundingBox, CAnimation, CGravity, CScore, CState> ComponentTuple;
typedef std::bitset<std::tuple_size_v<ComponentTuple>> ComponentMask;

class Entity {
 private:
  friend class EntityManager;

  bool        m_active{true};
  size_t      m_id{0};
  std::string m_tag{"default"};

  ComponentTuple m_components;
  ComponentMask m_component_mask;

  Entity(size_t id, const std::string &tag);

 template <typename T, typename Tuple>
 struct index_of;

 template <typename T>
 struct index_of<T, std::tuple<>> {
  static constexpr size_t value = 0;
 };

 template<typename T, typename U, typename ... Ts>
 struct index_of<T, std::tuple<U, Ts...>> {
  static const size_t value = 1 + index_of<T, std::tuple<Ts...>>::value;
 };

 template <typename T, typename... Ts>
   struct index_of<T, std::tuple<T, Ts...>> {
  static constexpr size_t value = 0;
 };

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