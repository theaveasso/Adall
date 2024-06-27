#include "Adall/EntityManager.hpp"
#include "Adall/Component.hpp"
#include <iostream>

int main() {
    EntityManager em{};

    auto e{em.add_entity("player")};

    auto a = e->has_component<CAnimation>();

    std::cout << "boolean contain " << a << std::endl;

    return 0;
}
