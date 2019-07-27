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
    
}

Board::~Board() {
    printf("board destructor running yo!");
}

void Board::printBoard() {
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            Tile t = getTile(i, j);

        }
    }
}

Tile Board::getTile(int x, int y) {
    
}

