#include "BoosAlien.hpp"

BoosAlien::BoosAlien()
{
    imgBoosAlien = LoadTexture("../Graphics/boos_prototype.png");
    alive = false;
}

BoosAlien::~BoosAlien()
{
    UnloadTexture(imgBoosAlien);

}

void BoosAlien::updateBoosAlien()
{
    if (alive){
        position.x += speedBoosAlien;

        if (position.x > GetScreenWidth() - imgBoosAlien.width - 25|| position.x < 25){
            alive = false;

        }

    }

}

void BoosAlien::spawn()
{
    position.y = 90;
    int side = GetRandomValue(0,1);

    if (side == 0){
        position.x = 25;
        speedBoosAlien = 3;
    }else{
        position.x = GetScreenWidth() - imgBoosAlien.width - 25;
        speedBoosAlien = 3;
    }
    alive=true;
}

void BoosAlien::drawBoosAlien()
{
    if (alive){
        DrawTextureV(imgBoosAlien, position, WHITE);
    }
}

Rectangle BoosAlien::getRect()
{
    if (alive)
        return {position.x, position.y, float(imgBoosAlien.width), float(imgBoosAlien.height)};
    else
        return {position.x, position.y, 0, 0};
}
