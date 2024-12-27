#include "Block.hpp"

Block::Block(Vector2 position)
{
    this ->position = position;
}

void Block::drawBlock()
{
    DrawRectangle(position.x, position.y, 3, 3, {0, 203, 177, 255});
}

Rectangle Block::getRect()
{
    Rectangle rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.width = 3;
    rect.height = 3;
    return rect;
}
