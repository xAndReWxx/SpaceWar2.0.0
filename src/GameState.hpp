#pragma once
#include "SpaceShip.hpp"
#include "Obstacle.hpp"
#include "Alien.hpp"
#include "BoosAlien.hpp"
#include "State.hpp"
#include "Game.hpp"
#include "GameOverState.hpp"
#include <string>
#include <iostream>
using namespace std;

class GameState :  SpaceShip, Obstacle, BoosAlien, Laser,public State
{
private:
    Color gray = {29, 29, 27, 255};
    Color yellow = {243, 216, 63, 255};
    Font font = LoadFontEx("Font/monogram.ttf", 65, 0, 0);
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
    Texture2D backgroundGameState;
    Sound alienHitSound;
    Sound spaceShipHitSound;
    Music endGameMusic;
    Music music;
public:
    GameState();
    ~GameState();
    void draw(Game& game);
    void update(Game& game);
    void handleInput(Game& game);
    void destroyLaser();
    void moveAliens();
    void moveDownAliens(int distance);
    void alienShootLaser();
    void gameOver();
    void drawTheInterFace();
    void drawLevel();
    void drawAndUpdateLives();
    string FormatWithLeadingZeros(int number, int width);
    int score;
    int aliensDirection;
    vector<Laser> aliensLaser;
    constexpr static float alienLaserShootDelay = 0.35;
    float lastAlienShootTime;
    int lives;
    bool running;
};
