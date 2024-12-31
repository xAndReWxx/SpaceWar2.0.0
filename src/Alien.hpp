#pragma once
#include <raylib.h>
#include "Positions.hpp"

class Alien : public Positions{
private:
public:
    Alien(int typeAlien, Vector2 position);
    // Texture2D imageAlien;
    static Texture2D imgAliens[3];
    int typeAlien;
    void drawAlien();
    Rectangle getRect();
    static void unloadImgAliens();
    void updateAlien(int direction);
    int getTypeAlien();
};