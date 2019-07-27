/**
 * @file board.cpp
 * @author zach kemp
 * @brief board cpp file with functions and such
 * @version 0.1
 * @date 2019-07-27
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "board.hpp"
#include <stdio.h>
#include <cstdio>

Board::Board() {
    printf("Constructing a new board.\n");
    // Set everything to nullpts at first
    // That way we can safely destruct later
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            this->boardArray[i][j] = nullptr;
        }
    }
}

Board::~Board() {
    printf("Board destructor running yo!\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            Tile* t = getTile(i, j);
            // Delete the tile if it exists
            if (t != nullptr) {
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
            if (t != nullptr) {
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

void Board::removeTile(int x, int y) {
    // Get the tile, delete it and set the location to a nullptr
    Tile* tile = this->getTile(x, y);
    delete tile;
    boardArray[x][y] = nullptr;
}

void Board::printBlankTile() {
    printf("[ X ]");
    /*
    printf("***** ");
    printf("*   * ");
    printf("***** ");
    */
}
