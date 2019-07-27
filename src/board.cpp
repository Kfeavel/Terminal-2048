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
}

Board::~Board() {
    printf("Board destructor running yo!\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            Tile* t = getTile(i, j);
            // Delete the tile
            delete t;
        }
    }
}

void Board::printBoard() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            Tile* t = getTile(i, j);
            // Print the tile
            t->print();
        }
    }
}

Tile* Board::getTile(int x, int y) {
    return this->boardArray[x][y];
}

