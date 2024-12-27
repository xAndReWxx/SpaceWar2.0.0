#pragma once
#include "State.hpp"
#include "Game.hpp"
#include "GameState.hpp"
#include "button.hpp"
#include <iostream>
using namespace std;

class MainMenuState : public State {
protected:
    Texture2D backgroundMainMenu;
    Music menuMusic;
    Button buttonPlay = {"Graphics/buttonPlay.png", {GetScreenWidth() / 2.0f, (GetScreenHeight() / 2.0f) - 80.0f}};
    Button buttonExit = {"Graphics/buttonExit.png", {(GetScreenWidth() / 2.0f) + 4, (GetScreenHeight() / 2.0f) + 80.0f}};
public:
    MainMenuState();
    ~MainMenuState();
    
    void handleInput(Game& game) override;

    void update(Game& game) override;
    
    void draw(Game& game) override;
};