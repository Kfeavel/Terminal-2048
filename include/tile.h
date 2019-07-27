/**
 * @file tile.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2019-07-27
 * 
 * @copyright Copyright (c) 2019
 * 
 */

class Tile {
    public:
        Tile();
        ~Tile();
        int getValue(void);
        void setValue(int);
        int getX(void);
        void setX(int);
        int getY(void);
        void setY(int);
    private:
        int value;
        int x;
        int y;
};