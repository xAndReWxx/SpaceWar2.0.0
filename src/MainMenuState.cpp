#include "MainMenuState.hpp"


MainMenuState::MainMenuState()
{
    backgroundMainMenu = LoadTexture("Graphics/backgroundPlayingGame.jpg");
}

MainMenuState::~MainMenuState()
{
    UnloadTexture(backgroundMainMenu);
}

void MainMenuState::handleInput(Game& game)
{
    if (buttonPlay.isPressed(GetMousePosition(), IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
        State* loco = new GameState(); 
        game.changeState(loco);
    }
    else if (buttonExit.isPressed(GetMousePosition(), IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
        cout << "\n\n\n\nExit Button Pressed\n\n\n\n\n" ;

}

void MainMenuState::update(Game& game)
{

}

void MainMenuState::draw(Game& game)
{
    DrawTexture(backgroundMainMenu, 0, 0, WHITE);
    buttonPlay.buttonDraw();
    buttonExit.buttonDraw();
}
