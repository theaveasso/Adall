#include "Adall/EntityManager.hpp"

#include <memory>
#include <map>

EntityManager::EntityManager() = default;

std::shared_ptr<Entity> EntityManager::add_entity(const std::string &tag) {
    auto e{std::shared_ptr<Entity>(new Entity(m_total_entities, tag))};

    m_entities_to_add.push_back(e);
    m_entity_map[tag].push_back(e);

    return e;
}

const EntityVec &EntityManager::get_entities() {
    return m_entities;
}

const EntityVec &EntityManager::get_entities(const std::string &tag) {
    return m_entity_map[tag];
}

void EntityManager::update() {
    for (auto &e : m_entities_to_add) {
        m_entities.push_back(e);
        m_entity_map[e->tag()];
    }

    m_entities_to_add.clear();

    for (auto &e : m_entities) {
        if (!e->is_active()) {
            m_entities_to_add.push_back(e);
        }
    }

    remove_dead_entities(m_entities_to_add);

    m_entities_to_add.clear();
}

void EntityManager::remove_dead_entities(EntityVec &entity_vec) {
    for (auto &e : entity_vec) {
        // TODO find a better algorithm to remove the entities from vec
    }
}
