#ifndef ADALL_INCLUDE_ADALL_PHYSICS_HPP_
#define ADALL_INCLUDE_ADALL_PHYSICS_HPP_

#include "Adall/Vec2.hpp"
#include "Adall/Entity.hpp"

#include <memory>

class Physics {

public:
    Vec2 get_overlap(std::shared_ptr<Entity> e1, std::shared_ptr<Entity> e2);

    Vec2 get_prev_overlap(std::shared_ptr<Entity> e1, std::shared_ptr<Entity> e2);
};

#endif //ADALL_INCLUDE_ADALL_PHYSICS_HPP_