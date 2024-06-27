#include "Adall/Physics.hpp"
#include "Adall/Component.hpp"

Vec2 Physics::get_overlap(std::shared_ptr<Entity> e1, std::shared_ptr<Entity> e2) {
    // TODO: return the overlap rectangle size of the bounding boxs of entity e1 and e2
    // auto bb1{e1->get_component<CBoundingBox>()};
    // auto bb2{e2->get_component<CBoundingBox>()};

    return {0, 0};
}

Vec2 Physics::get_prev_overlap(std::shared_ptr<Entity> e1, std::shared_ptr<Entity> e2) {
    // TODO: return the overlap rectangle size of the bounding boxs of prev entity e1 and e2

    return {0, 0};
}

