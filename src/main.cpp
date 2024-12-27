#include <raylib.h>
#include "Game.hpp"
#include <string>
#include <string.h>
#include "MainMenu.hpp"
string FormatWithLeadingZeros(int number, int width)
{
    string numberText = to_string(number);
    int leadingZeros = width - numberText.length();
    return numberText = string(leadingZeros, '0') + numberText;
}

using namespace std;
int main()
{
    Color gray = {29, 29, 27, 255};
    Color yellow = {243, 216, 63, 255};
    int offset = 50;
    int windowWidth = 750;
    int windowHight = 700;
    InitWindow(windowWidth + offset, windowHight + 2 * offset, "Welcome To Our Game");
    SetTargetFPS(60);
    // ToggleFullscreen();
    Font font = LoadFontEx("Font/monogram.ttf", 65, 0, 0);
    Texture2D livesImage = LoadTexture("Graphics/imgSpaceShip.png");
    // احنا عاملين الدكلريشن هنا علشان ميحصلش overlayer للاليمنتز
    Game game;
    MainMenu menu;
    while (WindowShouldClose() == false)
    {
        // game.handleGameInput();
        // game.updateGame();
        menu.handleInputMainMenu();
        BeginDrawing();
        ClearBackground(gray);
        menu.drawMainMenu();
        // DrawRectangleRoundedLines((Rectangle){10, 10, 780, 780}, 0.18f, 20, yellow);
        // DrawLineEx({25, 730}, {775, 730}, 3, yellow);
        // if (game.running)
        // {
        //     DrawTextEx(font, "Level 01", {570, 740}, 34, 2, yellow);
        // }
        // else
        // {
        //     DrawTextEx(font, "Game Over", {570, 740}, 34, 2, yellow);
        // }
        // float x = 50.0;
        // for (int i = 0; i < game.lives; i++)
        // {
        //     DrawTextureV(livesImage, {x, 735}, WHITE);
        //     x += 70;
        // }

        // DrawTextEx(font, "SCORE", {50, 15}, 34, 2, yellow);
        // string scoreText = FormatWithLeadingZeros(game.score, 5);
        // DrawTextEx(font, scoreText.c_str(), {50, 40}, 34, 2, yellow);

        // game.drawGame();
        // // Space.fireLaser();

        EndDrawing();
    }

    CloseWindow();
}