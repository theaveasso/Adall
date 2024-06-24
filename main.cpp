//#include "Adall/Vec2.hpp"
//#include "Adall/Component.hpp"

#include <iostream>

#include <SFML/Graphics.hpp>

int main() {
//    CBoundingBox a(Vec2(10, 10));
//
//    std::cout << a.size.x << "\n";

    sf::RenderWindow window(sf::VideoMode(523, 234), "test");

    while (window.isOpen()) {
        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();
        window.display();
    }

    return 0;
}
