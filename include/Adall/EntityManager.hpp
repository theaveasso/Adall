#ifndef ADALL_INCLUDE_ADALL_ENTITYMANAGER_HPP_
#define ADALL_INCLUDE_ADALL_ENTITYMANAGER_HPP_

#include <vector>
#include <memory>
#include <map>

#include "Adall/Entity.hpp"

class Entity;

typedef std::vector<std::shared_ptr<Entity>> EntityVec;
typedef std::map<std::string, EntityVec> EntityMap;

class EntityManager {
 private:
  EntityVec entities_;
  EntityVec entities_to_add_;
  EntityMap entity_map_;
  size_t total_entities_{0};

  void remove_dead_entities(EntityVec &entity_vec);

 public:
  EntityManager();

  void update();

  std::shared_ptr<Entity> add_entity(const std::string &tag);

  const EntityVec &get_entities();

  const EntityVec &get_entities(const std::string &tag);
};

#endif //ADALL_INCLUDE_ADALL_ENTITYMANAGER_HPP_