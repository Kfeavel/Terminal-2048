/**
 * @file game_controller.h
 * @author Keeton Feavel, Zack Kemp
 * @brief The main game logic controller. Controls board logic and tile movement.
 * @version 0.1
 * @date 2019-07-27
 * 
 * @copyright Copyright (c) 2019
 * 
 */

// Include local classes
#include "tile.h"
#include "board.h"

class GameController {
    public:
        /**
         * @brief Construct a new Game Controller object
         * 
         */
        GameController();
        /**
         * @brief Destroy the Game Controller object
         * 
         */
        ~GameController();

        /**
         * @brief Direction enumeration. Used for specifying movement or neighbor direction
         * 
         */
        enum Direction {
            left,
            right,
            top,
            bottom
        };

    private:
        /**
         * @brief 
         * 
         * @param direction 
         */
        void move(Direction direction);
        /**
         * @brief 
         * 
         * @param direction 
         * @param source 
         */
        void checkNeighbor(Direction direction, Tile source);
        /**
         * @brief 
         * 
         * @param x 
         * @param y 
         */
        void combineTiles(Tile x, Tile y);
};