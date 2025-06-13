#include "SpaceShip.hpp"

SpaceShip::SpaceShip()
{
    imgSpaceShip = LoadTexture("../Graphics/imgSpaceShip.png");
    position.x = (GetScreenWidth() - imgSpaceShip.width) / 2;
    position.y = GetScreenHeight() - imgSpaceShip.height - 100;
    lastFireTime = 0.0;
}

SpaceShip::~SpaceShip()
{
    UnloadTexture(imgSpaceShip);
}

void SpaceShip::drawSpaceShip()
{
    DrawTextureV(imgSpaceShip, position, WHITE);
}


void SpaceShip::fireLaser(){
    if (GetTime() - lastFireTime >= 0.35)
    {
        lasers.push_back(Laser({float(position.x + imgSpaceShip.width/2) - 3,position.y},-5));
        lastFireTime = GetTime();
    }
}


void SpaceShip::moveRightSpaceShip(){
    position.x += 7.5;
    if (position.x > (GetScreenWidth() - imgSpaceShip.width - 25))
    {
        position.x = (GetScreenWidth() - imgSpaceShip.width - 25);
    }
}

void SpaceShip::moveLiftSpaceShip(){
    position.x -= 7.5;
    if (position.x < 25)
    {
        position.x = 25;
    }
}

void SpaceShip::moveUpSpaceShip(){
    position.y -= 7.5;
    if (position.y < (GetScreenHeight() - (GetScreenHeight() / 4.0f)))
    {
        position.y = (GetScreenHeight() - (GetScreenHeight() / 4.0f));
    }
}

void SpaceShip::moveDownSpaceShip(){
    position.y += 7.5;
    if (position.y > (GetScreenHeight() - imgSpaceShip.height) -70)
    {
        position.y = GetScreenHeight() - imgSpaceShip.height -70;
    }
}

Rectangle SpaceShip::getRect()
{   Rectangle rect;
    rect.x = position.x;
    rect.y = position.y;
    rect.width = float(imgSpaceShip.width);
    rect.height = float(imgSpaceShip.height);
    return rect;
}

void SpaceShip::resetSpaceShip()
{

    position.x =( GetScreenWidth() - imgSpaceShip.width) / 2.0f;
    position.y =( GetScreenWidth() - imgSpaceShip.height) - 100;
    lasers.clear();


}
