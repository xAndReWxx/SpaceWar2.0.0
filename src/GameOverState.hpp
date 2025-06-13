#pragma once
#include "C:\raylib\raylib\src\raylib.h"
#include "State.hpp"
#include "GameState.hpp"


class GameOverState : public State{
private:
    Texture2D imgGameOver;
    State* newState;
    Music gameOverMusic;
    // Vector2 leftPos = {-400, 0}, rightPos = {800, 0};    under develop
    // Texture2D leftImg, rightImg;                         under develop
    // float delayTime = 0.01F;                             under develop
    // double lastTimeImgDraw = GetTime();                  under develop

public:
    GameOverState();
    ~GameOverState();
    void draw(Game& game) ;
    void handleInput(Game& game) ;
    void update(Game& game);

};