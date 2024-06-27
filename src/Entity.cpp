#include "Adall/Entity.hpp"

#include "../../../../../Library/Developer/CommandLineTools/SDKs/MacOSX14.4.sdk/System/Library/Frameworks/ImageIO.framework/Headers/CGImageAnimation.h"

Entity::Entity(const size_t id, const std::string &tag) {
    m_id = id;
    m_tag = tag;
    m_components = {};
}

void Entity::destroy() {
    m_active = false;
}

bool Entity::is_active() {
    if (has_component<CLifespan>()) {
        m_active = get_component<CLifespan>().remaining > 0;
    }

    return m_active;
}

size_t Entity::id() const {
    return m_id;
}

const std::string &Entity::tag() const {
    return m_tag;
}

template<typename T>
bool Entity::has_component() const {
    static_assert(index_of<T, ComponentTuple>::value < std::tuple_size_v<ComponentTuple>, "Component not found in tuple");
    constexpr size_t index{index_of<T, ComponentTuple>::value};

    return m_component_mask[index];
}

template<typename T, typename... TArgs>
T &Entity::add_component(TArgs &&... mArgs) {
    static_assert(index_of<T, ComponentTuple>::value < std::tuple_size_v<ComponentTuple>, "Component not found in tuple");

    constexpr size_t index{index_of<T, ComponentTuple>::value};
    T& component{std::get<T>(m_components)};
    component = T(std::forward<TArgs>(mArgs)...);

    m_component_mask.set(index, true);

    return component;
}

template<typename T>
T &Entity::get_component() {
    static_assert(index_of<T, ComponentTuple>::value < std::tuple_size_v<ComponentTuple>, "Component not found in tuple");

    return std::get<T>(m_components);
}

template<typename T>
const T &Entity::get_component() const {
    static_assert(index_of<T, ComponentTuple>::value < std::tuple_size_v<ComponentTuple>, "Component not found in tuple");

    return std::get<T>(m_components);
}

template<typename T>
void Entity::remove_component() {
    static_assert(index_of<T, ComponentTuple>::value < std::tuple_size_v<ComponentTuple>, "Component not found in tuple");

    constexpr size_t index = index_of<T, ComponentTuple>::value;
    get_component<T>() = T{};
    m_component_mask.set(index, false);
}

template bool Entity::has_component<CTransform>() const;
template bool Entity::has_component<CLifespan>() const;
template bool Entity::has_component<CInput>() const;
template bool Entity::has_component<CBoundingBox>() const;
template bool Entity::has_component<CAnimation>() const;
template bool Entity::has_component<CGravity>() const;
template bool Entity::has_component<CScore>() const;
template bool Entity::has_component<CState>() const;

template void Entity::remove_component<CTransform>();
template void Entity::remove_component<CLifespan>();
template void Entity::remove_component<CInput>();
template void Entity::remove_component<CBoundingBox>();
template void Entity::remove_component<CAnimation>();
template void Entity::remove_component<CGravity>();
template void Entity::remove_component<CScore>();
template void Entity::remove_component<CState>();

template CTransform& Entity::get_component<CTransform>();
template CLifespan& Entity::get_component<CLifespan>() ;
template CInput& Entity::get_component<CInput>() ;
template CBoundingBox& Entity::get_component<CBoundingBox>() ;
template CAnimation& Entity::get_component<CAnimation>() ;
template CGravity& Entity::get_component<CGravity>() ;
template CScore& Entity::get_component<CScore>() ;
template CState& Entity::get_component<CState>() ;

template const CTransform& Entity::get_component<CTransform>() const;
template const CLifespan& Entity::get_component<CLifespan>() const;
template const CInput& Entity::get_component<CInput>() const;
template const CBoundingBox& Entity::get_component<CBoundingBox>() const;
template const CAnimation& Entity::get_component<CAnimation>() const;
template const CGravity& Entity::get_component<CGravity>() const;
template const CScore& Entity::get_component<CScore>() const;
template const CState& Entity::get_component<CState>() const;

template CTransform& Entity::add_component<CTransform>(CTransform&&);
template CLifespan& Entity::add_component<CLifespan>(CLifespan&&);
template CInput& Entity::add_component<CInput>(CInput&&);
template CBoundingBox& Entity::add_component<CBoundingBox>(CBoundingBox&&);
template CAnimation& Entity::add_component<CAnimation>(CAnimation&&);
template CGravity& Entity::add_component<CGravity>(CGravity&&);
template CScore& Entity::add_component<CScore>(CScore&&);
template CState& Entity::add_component<CState>(CState&&);