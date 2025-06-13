#pragma once 
#include "C:\raylib\raylib\src\raylib.h"
#include "Positions.hpp"


class BoosAlien : public Positions{
private :
    Texture2D imgBoosAlien;
    int speedBoosAlien;



public :
    BoosAlien();
    ~BoosAlien();
    void updateBoosAlien();
    void spawn();
    void drawBoosAlien();
    Rectangle getRect();
    bool alive ;



 
};