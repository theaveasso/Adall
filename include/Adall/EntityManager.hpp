#ifndef ADALL_INCLUDE_ADALL_ENTITYMANAGER_HPP_
#define ADALL_INCLUDE_ADALL_ENTITYMANAGER_HPP_

#include <vector>
#include <map>
#include <memory>

#include "Adall/Entity.hpp"

class Entity;

typedef std::vector<std::shared_ptr<Entity>> EntityVec;
typedef std::map<std::string, EntityVec> EntityMap;

class EntityManager {
 private:
  EntityVec m_entities{};
  EntityVec m_entities_to_add{};
  EntityMap m_entity_map;
  size_t m_total_entities{0};

  void remove_dead_entities(EntityVec &entity_vec);

 public:
  EntityManager();

  void update();

  std::shared_ptr<Entity> add_entity(const std::string &tag);

  const EntityVec &get_entities();

  const EntityVec &get_entities(const std::string &tag);
};

#endif //ADALL_INCLUDE_ADALL_ENTITYMANAGER_HPP_