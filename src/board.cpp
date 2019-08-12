/**
 * @file board.cpp
 * @author Keeton Feavel & Zack Kemp
 * @brief Controls all board related functions
 * @version 0.1
 * @date 2019-07-27
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "board.hpp"

Board::Board() {
    printf("Constructing a new board.\n");
    // Set everything to nullpts at first
    // That way we can safely destruct later
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            this->boardArray[i][j] = NULL;
        }
    }
    printf("Seeding rand()...\n");
    srand(time(NULL));
}

Board::~Board() {
    printf("Board destructor running yo!\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            Tile* t = getTile(i, j);
            // Delete the tile if it exists
            if (t != NULL) {
                delete t;
            }
        }
    }
}

void Board::printBoard() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            Tile* t = getTile(i, j);
            // Print the tile
            if (t != NULL) {
                t->print();
            } else {
                this->printBlankTile();
            }
        }
        // Print a new line for next row
        printf("\n");
    }
    printf("Please input a move: \n");
}

Tile* Board::getTile(int x, int y) {
    return this->boardArray[x][y];
}

void Board::insertTile(Tile *tile) {
    // Get the X and Y
    int x = tile->getX();
    int y = tile->getY();
    // Insert the tile at that location
    this->boardArray[x][y] = tile;
}

void Board::removeTile(int x, int y) {
    // Get the tile, delete it and set the location to a nullptr
    Tile* tile = this->getTile(x, y);
    delete tile;
    boardArray[x][y] = nullptr;
}

void Board::printBlankTile() {
    printf("[   ]");
    /*
    printf("***** ");
    printf("*   * ");
    printf("***** ");
    */
}

void Board::addRandomTileToBoard() {
    // Find a random location that is blank
    int x = rand() % 4;
    int y = rand() % 4;
    int val = 0;
    while (this->getTile(x, y) != NULL) {
        // If we've searched 16 times and can't find anything
        // Check if the board isn't full
        x = rand() % 4;
        y = rand() % 4;
    }
    printf("Open Position Found: %i %i\n", x, y);
    // Generate a random number between 0 and 100
    Tile *tile = nullptr;
    int chance = rand() % 101;
    if (chance < 90) {
        // Spawn a 2 tile
        val = 2;
    } else {
        // Spawn a 4 tile
        val = 4;
    }
    // Create the new tile
    tile = new Tile(val, x, y);
    // Insert the new tile
    this->insertTile(tile);
}

bool Board::checkForFullBoard() {
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            printf("Checking X: %i Y: %i\n", x, y);
            if (this->getTile(x, y) == NULL) {
                printf("Board open at %i %i\n", x, y);
                return false;
            }
        }
    }
    printf("Board is full according to checkForFullBoard()\n");
    return true;
}