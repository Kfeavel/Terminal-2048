#include "game_controller.hpp"

GameController::GameController() {
    printf("Constructing a new GameContoller\n");
    startGame();
}

GameController::~GameController() {
    printf("Destroying GameContoller...\n");
}

void GameController::startGame() {
    printf("Starting 2048...\n");
    readInput();
}

void GameController::stopGame() {
    printf("Stopping 2048...\n");
}

void GameController::readInput() {
    // Create a keyboard key input variable
    char input = NULL;
    // While the user hasn't called the quit key
    while (input != 'q') {
        // Continue to read input and call functions
        input = getchar();
        switch (input) {
            case 'w':
                GameController::move(top);
                break;
            case 'a':
                GameController::move(left);
                break;
            case 's':
                GameController::move(bottom);
                break;
            case 'd':
                GameController::move(right);
                break;
            case 'q':
                stopGame();
                break;
            default:
                printf("Invalid option.\n");
                break;
        }
    }
}

void GameController::move(GameController::Direction direction) {
    switch (direction) {
        case top:
            printf("Move upward.\n");
            break;
        case bottom:
            printf("Move downward.\n");
            break;
        case left:
            printf("Move left.\n");
            break;
        case right:
            printf("Move right.\n");
            break;
        default:
            printf("Invalid direction.\n");
            break;
    }
}

void GameController::checkNeighbor(GameController::Direction direction, Tile source) {

}

void GameController::combineTiles(Tile x, Tile y) {

}