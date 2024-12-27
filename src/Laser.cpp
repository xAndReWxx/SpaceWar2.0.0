#include "Laser.hpp"
#include <iostream>
Laser::Laser(Vector2 position, int speed)
{
    this -> position = position;
    this -> speed = speed;
    imgLaser = LoadTexture("Graphics/spaceShipLaser.png");
    active = true;
}

Laser::~Laser()
{
    UnloadTexture(imgLaser);
     
}

void Laser::drawLaser()
{
    if (active)
    DrawTextureV(imgLaser, position, WHITE);

}

Rectangle Laser::getRect()
{
    Rectangle rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.width = float(imgLaser.width);
    rect.height = float(imgLaser.height);
    return rect;
}

void Laser::updateLaser()
{

position.y += speed;

if (active){
    if (position.y > GetScreenHeight() || position.y< 0){
        active = false ;
    }
}

}

