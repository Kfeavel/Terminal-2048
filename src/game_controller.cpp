#include "game_controller.hpp"

GameController::GameController() {
    printf("Constructing a new GameContoller\n");
    startGame();
}

GameController::~GameController() {
    printf("Destroying GameContoller...\n");
    // Destroy the board
    delete this->board;
}

void GameController::startGame() {
    printf("Starting 2048...\n");
    // Construct a new board
    this->board = new Board();
    // Start reading user input
    readInput();
}

void GameController::stopGame() {
    printf("Stopping 2048...\n");
    // Print score to screen
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
    }
}

void GameController::checkNeighbor(GameController::Direction direction, Tile* source) {
    switch (direction) {
        case top:
            printf("Check upward.\n");
            printf("%i", source->getValue());
            break;
        case bottom:
            printf("Check downward.\n");
            printf("%i", source->getValue());
            break;
        case left:
            printf("Check left.\n");
            printf("%i", source->getValue());
            break;
        case right:
            printf("Check right.\n");
            printf("%i", source->getValue());
            break;
    }
}

void GameController::combineTiles(Tile* stay, Tile* remove) {
    // Get both values and combine them
    int stayVal = stay->getValue();
    int remVal = remove->getValue();
    int combined = stayVal + remVal;
    stay->setValue(combined);
    // Get the X & Y for the removed tile and call the remover function
    int remX = remove->getX();
    int remY = remove->getY();
    board->removeTile(remX, remY);
}