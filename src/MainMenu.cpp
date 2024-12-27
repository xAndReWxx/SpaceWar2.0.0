#include "MainMenu.hpp"
#include <iostream>
using namespace std;


MainMenu::MainMenu()
{
    backgroundMainMenu = LoadTexture("Graphics/backgroundPlayingGame.jpg");
}

MainMenu::~MainMenu()
{
    UnloadTexture(backgroundMainMenu);
}

void MainMenu::handleInputMainMenu()
{
    if (buttonPlay.isPressed(GetMousePosition(), IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
        cout << "\n\n\n\nPlay Button Pressed\n\n\n\n\n" ;
    else if (buttonExit.isPressed(GetMousePosition(), IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
        cout << "\n\n\n\nExit Button Pressed\n\n\n\n\n";
}

void MainMenu::updateMainMenu()
{

}

void MainMenu::drawMainMenu()
{
    DrawTexture(backgroundMainMenu, 0, 0, WHITE);
    buttonPlay.buttonDraw();
    buttonExit.buttonDraw();
}
