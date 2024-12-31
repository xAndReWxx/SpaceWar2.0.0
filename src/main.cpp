#include <raylib.h>
#include "Game.hpp"


using namespace std;





int main()
{

    // insialization session
    int offset = 50;
    int windowWidth = 750; // 800
    int windowHight = 700; // 800
    InitWindow(windowWidth + offset, windowHight + 2 * offset, "Space War");
    InitAudioDevice();
    SetTargetFPS(60);
    

    ////////////////////////////////////////////////////////////////////////
    Game game;

    while (WindowShouldClose() == false){

        game.handleInputGame();

        BeginDrawing();

        game.updateGame();

        game.drawGame();

        EndDrawing();

    }

    CloseWindow();
    CloseAudioDevice();

}