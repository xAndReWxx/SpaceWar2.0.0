#include "Alien.hpp"

Texture2D Alien::imgAliens[3] = {};

Alien::Alien(int typeAlien, Vector2 position)
{
    this->position = position;
    this->typeAlien = typeAlien;

    if (imgAliens[typeAlien - 1].id == 0)

        switch (typeAlien)
        {
        case 1:
            imgAliens[0] = LoadTexture("Graphics/prototype_1.png");
            break;

        case 2:
            imgAliens[1] = LoadTexture("Graphics/prototype_2.png");
            break;

        case 3:
            imgAliens[2] = LoadTexture("Graphics/prototype_3.png");
            break;

        default:
            imgAliens[0] = LoadTexture("Graphics/prototype_1.png");
            break;
        }
}


void Alien::drawAlien()
{
    DrawTextureV(imgAliens[typeAlien - 1], position, WHITE);
}

Rectangle Alien::getRect()
{
    return {position.x, position.y, float(imgAliens[typeAlien - 1].width), float(imgAliens[typeAlien - 1].height)};
}

void Alien::unloadImgAliens()
{
    for (int i = 0; i < 4; i++)
    {
        UnloadTexture(imgAliens[i]);
    }
}

int Alien::getTypeAlien()
{

    return typeAlien;
}

void Alien::updateAlien(int direction)
{
    position.x += direction;
}
