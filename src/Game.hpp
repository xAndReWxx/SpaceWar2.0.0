#pragma once
#include "SpaceShip.hpp"
#include "Obstacle.hpp"
#include "Alien.hpp"
#include "BoosAlien.hpp"
class Game : public SpaceShip, Obstacle, Alien, BoosAlien, Laser
{
private:
    vector<Obstacle> obstacles;
    vector<Obstacle> createObstacle();
    vector<Alien> createAlien();
    vector<Alien> aliens;
    BoosAlien boos;
    float boosAlienDelay;
    float boosTimeLastSpawn;
    void checkFOrCollision();
    void reGame();
    void initGame();

public:
    Game();
    ~Game();
    void drawGame();
    void updateGame();
    void handleGameInput();
    void destroyLaser();
    void moveAliens();
    void moveDownAliens(int distance);
    void alienShootLaser();
    void gameOver();
    int score;
    int aliensDirection;
    vector<Laser> aliensLaser;
    constexpr static float alienLaserShootDelay = 0.35;
    float lastAlienShootTime;
    int lives;
    bool running;
};
