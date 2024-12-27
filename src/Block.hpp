#pragma once 
#include <raylib.h>
#include "Positions.hpp"
class Block : private Positions{
private:


public:
    Block(Vector2 positionBlock);
    void drawBlock();
    Rectangle getRect();

};