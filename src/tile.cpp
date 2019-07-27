/**
 * @file tile.cpp
 * @author zach kemp
 * @brief tile cpp file with actual functions and whatnot
 * @version 0.1
 * @date 2019-07-27
 * 
 * @copyright Copyright (c) 2019
 * 
 */

#include "tile.h"
#include <stdio.h>
#include <cstdio>

Tile::Tile(int v, int x, int y){
    setValue(v);
    setX(x);
    setY(y);
}

Tile::~Tile(){
    printf;
}

int Tile::getValue(){
    return this->value;
}

void Tile::setValue(int v){
    this->value = v;
}

int Tile::getX(){
    return this->x;
}

void Tile::setX(int x){
    this->x = x;
}

int Tile::getY(){
    return this->y;
}

void Tile::setY(int y){
    this->y = y;
}