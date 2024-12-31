#pragma once
#include <raylib.h>
#include <vector>
#include "Laser.hpp"
#include "Positions.hpp"
using namespace std;
class SpaceShip : private Positions{
protected:
    Texture2D imgSpaceShip;
    double lastFireTime;
public:
    vector <Laser> lasers;
    SpaceShip();
    ~SpaceShip();
    void drawSpaceShip();
    void fireLaser();
    void moveRightSpaceShip();
    void moveLiftSpaceShip();
    void moveUpSpaceShip();
    void moveDownSpaceShip();
    Rectangle getRect();
    void resetSpaceShip();

};