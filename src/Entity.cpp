#include "Adall/Entity.hpp"

Entity::Entity(const size_t id, const std::string &tag) : m_id(id), m_tag(tag), m_components() {
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
    return get_component<T>().has;
}

template<typename T, typename... TArgs>
T &Entity::add_component(TArgs &&... mArgs) {
    auto &component = get_component<T>();
    component = T(std::forward<TArgs>(mArgs)...);
    component.has = true;

    return component;
}

template<typename T>
T &Entity::get_component() {
    return std::get<T>(m_components);
}

template<typename T>
const T &Entity::get_component() const {
    return std::get<T>(m_components);
}

template<typename T>
void Entity::remove_component() {
    get_component<T>() = T();
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

template CTransform &Entity::get_component<CTransform>();
template CLifespan &Entity::get_component<CLifespan>();
template CInput &Entity::get_component<CInput>();
template CBoundingBox &Entity::get_component<CBoundingBox>();
template CAnimation &Entity::get_component<CAnimation>();
template CGravity &Entity::get_component<CGravity>();
template CScore &Entity::get_component<CScore>();
template CState &Entity::get_component<CState>();

template const CTransform &Entity::get_component<CTransform>() const;
template const CLifespan &Entity::get_component<CLifespan>() const;
template const CInput &Entity::get_component<CInput>() const;
template const CBoundingBox &Entity::get_component<CBoundingBox>() const;
template const CAnimation &Entity::get_component<CAnimation>() const;
template const CGravity &Entity::get_component<CGravity>() const;
template const CScore &Entity::get_component<CScore>() const;
template const CState &Entity::get_component<CState>() const;

template CTransform &Entity::add_component<CTransform>(Vec2 &&);
template CLifespan &Entity::add_component<CLifespan>(CLifespan &&);
template CInput &Entity::add_component<CInput>(CInput &&);
template CBoundingBox &Entity::add_component<CBoundingBox>(Vec2 const &);
template CAnimation &Entity::add_component<CAnimation>(Animation &, bool &&);
template CGravity &Entity::add_component<CGravity>(CGravity &&);
template CScore &Entity::add_component<CScore>(CScore &&);
template CState &Entity::add_component<CState>(CState &&);