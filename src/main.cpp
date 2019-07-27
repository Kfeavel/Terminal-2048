#include "main.hpp"

int main() {
    // Construct a new GameController and let it take over control
    GameController* gc = new GameController();
    // Once the game controller gives up control delete it and return.
    delete gc;
    return 0;
}