#pragma once
#include "GameState.hpp"
#include "button.hpp"

class MainMenu{
protected:
    Texture2D backgroundMainMenu;
    Button buttonPlay = {"Graphics/buttonPlay.png", {GetScreenWidth() / 2.0f, (GetScreenHeight() / 2.0f) - 80.0f}};
    Button buttonExit = {"Graphics/buttonExit.png", {(GetScreenWidth() / 2.0f) + 4, (GetScreenHeight() / 2.0f) + 80.0f}};
public:

    MainMenu();

    ~MainMenu();
    
    void handleInputMainMenu() ;

    void updateMainMenu();
    
    void drawMainMenu();
};