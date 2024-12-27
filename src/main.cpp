#include <raylib.h>
#include "Game.hpp"

using namespace std;

int main()
{

    // insialization session
    Color gray = {29, 29, 27, 255};
    int offset = 50;
    int windowWidth = 750;
    int windowHight = 700;
    InitWindow(windowWidth + offset, windowHight + 2 * offset, "Welcome To Our Game");
    SetTargetFPS(60);

    ////////////////////////////////////////////////////////////////////////
    Game game;

    while (WindowShouldClose() == false){
        game.handleInputGame();
        BeginDrawing();
        ClearBackground(gray);

        game.updateGame();

        game.drawGame();


        EndDrawing();

    }

    CloseWindow();

    
return 0 ;
}