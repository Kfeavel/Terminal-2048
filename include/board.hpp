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

// Include local classes
#include "tile.hpp"
// Include system libraries
#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <ctime>

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

        /**
         * @brief Inserts a tile into the board
         * 
         * @param tile The tile to be inserted
         */
        void insertTile(Tile *tile);

        /**
         * @brief Removes a tile at a position from the board
         * 
         * @param x X index of desired tile
         * @param y Y index of desired tile
         */
        void removeTile(int x, int y);

        /**
         * @brief Adds 2 random tiles to the board after each turn.
         * 
         */
        void addRandomTileToBoard();

        /**
         * @brief Checks if a board is full and ends the game if necessary
         * 
         */
        bool checkForFullBoard();

    private:
        /**
         * @brief Array of pointers to tiles which constitutes the board
         * (The typical 2048 board is 4x4, thus this is how we
         * are defining the size of our array.)
         * 
         */
        Tile* boardArray[4][4];

        /**
         * @brief Prints a blank tile for a nullptr in the board
         * 
         */
        void printBlankTile();
};

#endif