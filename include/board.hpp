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

class Board {
    public:
        Board();
        ~Board();
        void printBoard();
        Tile getTile(int x, int y);
    private:
        Tile array[][];
}