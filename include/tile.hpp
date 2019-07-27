/**
 * @file tile.h
 * @author Keeton Feavel and Zack Kemp
 * @brief tile header file with variables, etc
 * @version 0.1
 * @date 2019-07-27
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#ifndef TILE_H
#define TILE_H

#include <stdio.h>
#include <cstdio>

class Tile {
    public:
        /**
         * @brief Construct a new Tile object
         * 
         * @param v Tile value
         * @param x X coordinate
         * @param y Y coordinate
         */
        Tile(int v, int x, int y);
        /**
         * @brief Destroy the Tile object
         * 
         */
        ~Tile();
        /**
         * @brief Get the Value object
         * 
         * @return int Tile value (i.e. 2, 4, 8, 16, 32, etc.)
         */
        int getValue(void);
        /**
         * @brief Set the Value object
         * 
         */
        void setValue(int);
        /**
         * @brief Returns the X coordinate value
         * 
         * @return int X coordinate
         */
        int getX(void);
        /**
         * @brief Sets the X coordinate value
         * 
         */
        void setX(int);
        /**
         * @brief Returns the Y coordinate value
         * 
         * @return int Y coordinate
         */
        int getY(void);
        /**
         * @brief Sets the Y coordinate value
         * 
         */
        void setY(int);
    private:
        int value;
        int x;
        int y;
};

#endif