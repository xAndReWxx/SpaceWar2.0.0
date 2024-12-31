#include "GameOverState.hpp"

GameOverState::GameOverState()
{
    Color gray = {100,100,100,255};
    ClearBackground(gray);
    imgGameOver = LoadTexture("Graphics/backgroundGameOver.jpg"); 
    gameOverMusic = LoadMusicStream("Sounds/GameOverMusic.ogg");
    // leftImg = LoadTexture("Graphics/leftImgGameOver.jpg");   under develop
    // rightImg = LoadTexture("Graphics/rightGameOver.jpg");    under develop
    PlayMusicStream(gameOverMusic);
}

GameOverState::~GameOverState()
{
    UnloadTexture(imgGameOver);
    // UnloadTexture(leftImg);                                  under develop
    // UnloadTexture(rightImg);                                 under develop
    UnloadMusicStream(gameOverMusic);
}

void GameOverState::update(Game &game)
{
    UpdateMusicStream(gameOverMusic);
}

void GameOverState::draw(Game &game)
{
    DrawTexture(imgGameOver, 0, 0, WHITE);
   
}

void GameOverState::handleInput(Game &game)
{
    if (IsKeyPressed(KEY_ENTER))
    {
        newState = new GameState();
        game.changeState(newState);
    }
}









                //--------------- UNDER DEVELOP ------------------//

// bool con = true;

//     while (con)
//     {
//         double currentTime = GetTime();
//         if (currentTime - lastTimeImgDraw > delayTime)
//         {
//             if (rightPos.x >= 400)
//             {
//                 leftPos.x += 10;
//                 rightPos.x -= 1;
//                 lastTimeImgDraw = currentTime;
//             }
//             else
//             {
//                 con = false;
//             }
//         }
//         DrawTextureV(leftImg, leftPos, WHITE);
//         DrawTextureV(rightImg, rightPos, WHITE);
//     }
// }