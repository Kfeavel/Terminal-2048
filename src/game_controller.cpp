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
}