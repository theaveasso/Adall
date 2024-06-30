#include "Adall/GameEngine.hpp"

int main() {
    GameEngine game_engine;
    game_engine.init("assets/");
    game_engine.run();

    return 0;
}
