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
        /**
         * @brief Construct a new Board object
         * 
         */
        Board();
        /**
         * @brief Destroy the Board object
         * 
         */
        ~Board();
        /**
         * @brief Prints the board to the terminal
         * 
         */
        void printBoard();
        /**
         * @brief Get the Tile object
         * 
         * @param x X index of desired tile
         * @param y Y index of desired tile
         * @return Tile* Pointer to tile at the desired position
         */
        Tile* getTile(int x, int y);
    private:
        /**
         * @brief Array of tiles which constitutes the board
         * 
         */
        Tile** array;
};

#endif