#pragma once
#include <raylib.h>
#include "Positions.hpp"

class Alien : public Positions{
private:
public:
    Alien(int typeAlien = 0, Vector2 position = {0 , 0});
    // Texture2D imageAlien;
    static Texture2D imgAliens[3];
    int typeAlien;
    void drawAlien();
    Rectangle getRect();
    static void unloadImgAliens();
    void updateAlien(int direction);
    int getTypeAlien();
};