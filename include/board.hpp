/**
 * @file board.hpp
 * @author zach kemp
 * @brief board header file and all
 * @version 0.1
 * @date 2019-07-27
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef BOARD_H
#define BOARD_H

#include "tile.hpp"

class Board {
    public:
        Board();
        ~Board();
        void printBoard();
        Tile getTile(int x, int y);
    private:
        Tile** array;
};

#endif