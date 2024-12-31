#include "MainMenuState.hpp"


MainMenuState::MainMenuState()
{
    backgroundMainMenu = LoadTexture("Graphics/backgroundPlayingGame.jpg");
    menuMusic = LoadMusicStream("Sounds/ahShiitHereWeGoAgain.ogg");
    SetMusicVolume(menuMusic, 0.4);
    PlayMusicStream(menuMusic);
}

MainMenuState::~MainMenuState()
{
    UnloadTexture(backgroundMainMenu);
    UnloadMusicStream(menuMusic);
}

void MainMenuState::handleInput(Game& game)
{
    if (buttonPlay.isPressed(GetMousePosition(), IsMouseButtonPressed(MOUSE_LEFT_BUTTON))){
        State* loco = new GameState(); 
        game.changeState(loco);
    }
    else if (buttonExit.isPressed(GetMousePosition(), IsMouseButtonPressed(MOUSE_LEFT_BUTTON)))
        CloseWindow();
}

void MainMenuState::update(Game& game)
{
    UpdateMusicStream(menuMusic);

}

void MainMenuState::draw(Game& game)
{
    DrawTexture(backgroundMainMenu, 0, 0, WHITE);
    buttonPlay.buttonDraw();
    buttonExit.buttonDraw();
}
