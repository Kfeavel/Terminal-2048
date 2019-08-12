/**
 * @file game_controller.cpp
 * @author Keeton Feavel & Zack Kemp
 * @brief Controls all of the game logic and movement
 * @version 0.1
 * @date 2019-07-27
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "game_controller.hpp"

GameController::GameController() {
    printf("Constructing a new GameContoller\n");
    startGame();
}

GameController::~GameController() {
    printf("Destroying GameContoller...\n");
    // Destroy the board
    delete this->board;
    printf("Done deleting board.\n");
}

void GameController::startGame() {
    printf("Starting 2048...\n");
    // Construct a new board with a pointer to this controller
    this->board = new Board();
    // Insert the random tiles
    for (int i = 0; i < 2; i++) {
        board->addRandomTileToBoard();
    }
    // After we construct show the board
    this->board->printBoard();
    // Start reading user input
    readInput();
}

void GameController::stopGame() {
    printf("Game Over!\n");
    // Print score to screen
    return;
}

void GameController::readInput() {
    // Create a keyboard key input variable
    char input = NULL;
    // While the user hasn't called the quit key
    while (true) {
        // printf("Checking board status...\n");
        if (board->checkForFullBoard()) {
            // printf("The board is full. Stopping the game.\n");
            this->stopGame();
            return;
        }
        // Continue to read input and call functions
        input = getchar();
        switch (input) {
            case 'w':
                this->move(top);
                break;
            case 'a':
                this->move(left);
                break;
            case 's':
                this->move(bottom);
                break;
            case 'd':
                this->move(right);
                break;
            case 'q':
                // Call the stop game function and exit this function
                this->stopGame();
                return;
        }
        // Now that we have our input, call the appropriate logic functions and then
        // print the resulting board to the console.
        // Also, getChar gets the return key along with the input so we have to 
        // have this if statement to not double
        if (input != '\n') {
            // Insert the random tile
            board->addRandomTileToBoard();
            // Print the updated board
            board->printBoard();
        }
    }
}

void GameController::move(GameController::Direction direction) {
    switch (direction) {
        case top:
            printf("Move upward.\n");
            for (int x = 0; x < 4; x++) {
                for (int y = 0; y < 4; y++) {
                    Tile *tile = this->board->getTile(x, y);
                    if (tile != NULL) {
                        this->checkNeighbor(direction, tile);
                    }
                }
            }
            break;
        case bottom:
            printf("Move downward.\n");
            for (int x = 0; x < 4; x++) {
                for (int y = 0; y < 4; y++) {
                    Tile *tile = this->board->getTile(x, y);
                    if (tile != NULL) {
                        this->checkNeighbor(direction, tile);
                    }
                }
            }
            break;
        case left:
            printf("Move left.\n");
            for (int x = 0; x < 4; x++) {
                for (int y = 0; y < 4; y++) {
                    Tile *tile = this->board->getTile(x, y);
                    if (tile != NULL) {
                        this->checkNeighbor(direction, tile);
                    }
                }
            }
            break;
        case right:
            printf("Move right.\n");
            for (int x = 0; x < 4; x++) {
                for (int y = 0; y < 4; y++) {
                    Tile *tile = this->board->getTile(x, y);
                    if (tile != NULL) {
                        this->checkNeighbor(direction, tile);
                    }
                }
            }
            break;
    }
}

void GameController::checkNeighbor(GameController::Direction direction, Tile* source) {
    Tile *neighbor = NULL;
    switch (direction) {
        case top:
            printf("Check upward.\n");
            neighbor = this->board->getTile(source->getX(), source->getY() + 1);
            // Check if we can combine
            if (neighbor != NULL) {
                // If not null, compare values
                if (neighbor->getValue() == source->getValue()) {
                    // Pretty sure this isn't right since we're keeping the neighbor and
                    // removing the source, but I just need to test this for now. The whole
                    // sliding thing will be weird...
                    this->combineTiles(neighbor, source);
                }
            }
            break;
        case bottom:
            printf("Check downward.\n");
            neighbor = this->board->getTile(source->getX(), source->getY() - 1);
            // Check if we can combine
            if (neighbor != NULL) {
                // If not null, compare values
                if (neighbor->getValue() == source->getValue()) {
                    // Pretty sure this isn't right since we're keeping the neighbor and
                    // removing the source, but I just need to test this for now. The whole
                    // sliding thing will be weird...
                    this->combineTiles(neighbor, source);
                }
            }
            break;
        case left:
            printf("Check left.\n");
            neighbor = this->board->getTile(source->getX() - 1, source->getY());
            // Check if we can combine
            if (neighbor != NULL) {
                // If not null, compare values
                if (neighbor->getValue() == source->getValue()) {
                    // Pretty sure this isn't right since we're keeping the neighbor and
                    // removing the source, but I just need to test this for now. The whole
                    // sliding thing will be weird...
                    this->combineTiles(neighbor, source);
                }
            }
            break;
        case right:
            printf("Check right.\n");
            neighbor = this->board->getTile(source->getX() + 1, source->getY());
            // Check if we can combine
            if (neighbor != NULL) {
                // If not null, compare values
                if (neighbor->getValue() == source->getValue()) {
                    // Pretty sure this isn't right since we're keeping the neighbor and
                    // removing the source, but I just need to test this for now. The whole
                    // sliding thing will be weird...
                    this->combineTiles(neighbor, source);
                }
            }
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