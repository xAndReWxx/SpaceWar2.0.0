#pragma once
#include "C:\raylib\raylib\src\raylib.h"
#include "Positions.hpp"
#include <vector>
using namespace std;

class Laser : private Positions {

private:
    int speed;
    Texture2D imgLaser;
    vector<Laser>lasers;
public:

    bool active; 
    Laser(Vector2 position = {0, 0}, int speed = 0);
    ~Laser();
    void updateLaser();
    void drawLaser();
    Rectangle getRect();
};