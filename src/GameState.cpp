#include "GameState.hpp"
#include "Game.hpp"

using namespace std;

GameState::GameState()
{
    backgroundGameState = LoadTexture("../Graphics/backgroundGameState1.jpg");
    music = LoadMusicStream("../Sounds/mainMusic.ogg");
    alienHitSound = LoadSound("../Sounds/alienHit.ogg");
    spaceShipHitSound = LoadSound("../Sounds/spaceShipHit.ogg");
    createAlien();
    SetSoundVolume(alienHitSound, 0.3);
    // SetMusicVolume(music);
    PlayMusicStream(music);
    initGame();
}
GameState::~GameState()
{
    UnloadMusicStream(music);
    UnloadSound(alienHitSound);
    UnloadSound(spaceShipHitSound);
    UnloadTexture(backgroundGameState);
    ClearBackground(BLACK);
}

void GameState::draw(Game &game)
{
    DrawTexture(backgroundGameState, 0, 0, WHITE);
    drawTheInterFace();
    drawLevel();
    SpaceShip::drawSpaceShip();
    for (auto &laser : SpaceShip::lasers)
    {
        laser.drawLaser();
    }

    for (auto &obstacle : obstacles)
    {
        obstacle.drawObstacle();
    }

    for (auto &alien : aliens)
    {
        alien.drawAlien();
    }

    for (auto &laser : aliensLaser)
    {
        laser.drawLaser();
    }

    boos.drawBoosAlien();
    drawAndUpdateLives();
}

void GameState::update(Game &game)
{
    UpdateMusicStream(music);

    if (running)
    {

        double currentTime = GetTime();
        if (currentTime - boosTimeLastSpawn > boosAlienDelay)
        {
            boos.spawn();
            boosTimeLastSpawn = GetTime();
            boosAlienDelay = GetRandomValue(5, 10);
        }

        for (auto &laser : SpaceShip::lasers)
        {
            laser.updateLaser();
        }
        destroyLaser();
        alienShootLaser();
        for (auto &laser : aliensLaser)
        {
            laser.updateLaser();
        }

        moveAliens();

        boos.updateBoosAlien();

        checkFOrCollision();
    }
    //========================================================
    else
    {
        reGame();
        initGame();
        State *nextPhase = new GameOverState();
        game.changeState(nextPhase);
        
    }
}

//=====================================================
void GameState::handleInput(Game &game)
{

    if (running)

    {
        if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
        {
            SpaceShip::moveRightSpaceShip();
        }
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
        {
            SpaceShip::moveLiftSpaceShip();
        }
        if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
        {
            SpaceShip::moveUpSpaceShip();
        }
        if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
        {
            SpaceShip::moveDownSpaceShip();
        }
        if (IsKeyDown(KEY_SPACE))
        {
            SpaceShip::fireLaser();
        }
    }
}

void GameState::destroyLaser()
{
    for (auto it = SpaceShip::lasers.begin(); it != SpaceShip::lasers.end();)
    {
        if (!it->active)
            it = SpaceShip::lasers.erase(it);
        else
            ++it;
    }

    for (auto it = aliensLaser.begin(); it != aliensLaser.end();)
    {
        if (!it->active)
            it = aliensLaser.erase(it);
        else
            ++it;
    }
}

vector<Obstacle> GameState::createObstacle()
{
    int obstacleWidth = grid[0].size() * 3;
    float gap = (GetScreenWidth() - (3 * obstacleWidth)) / 4;

    for (int i = 0; i < 3; i++)
    {
        float offsetX = (i + 1) * gap + i * obstacleWidth;
        obstacles.push_back(Obstacle({offsetX, float(GetScreenWidth() - 200)}));
    }

    return obstacles;
}

vector<Alien> GameState::createAlien()
{
    vector<Alien> aliens;
    for (int row = 0; row < 5; row++)
    {
        int type = 1;
        for (int column = 0; column < 11; column++)
        {

            if (row == 0)
                type = 1;
            else if (row == 1 || row == 2)
                type = 2;
            else
                type = 3;

            float x = 75 + column * 55;
            float y = 110 + row * 55;
            aliens.push_back(Alien(type, {x, y}));
        }
    }
    return aliens;
}

void GameState::moveAliens()
{
    for (auto &alien : aliens)
    {
        if (alien.position.x + alien.imgAliens[alien.typeAlien - 1].width > GetScreenWidth() - 25)
        {
            aliensDirection = -1;
            moveDownAliens(4);
        }

        if (alien.position.x < 25)
        {
            aliensDirection = 1;
            moveDownAliens(4);
        }
        alien.updateAlien(aliensDirection);
    }
}

void GameState::moveDownAliens(int distance)
{
    for (auto &alien : aliens)
    {
        alien.position.y += distance;
    }
}

void GameState::alienShootLaser()
{

    double currentTime = GetTime();
    if (currentTime - lastAlienShootTime > alienLaserShootDelay && !aliens.empty())
    {

        int randInd = GetRandomValue(0, aliens.size() - 1);
        Alien &alien = aliens[randInd];
        aliensLaser.push_back(Laser({alien.position.x + alien.imgAliens[alien.typeAlien - 1].width / 2,
                                     alien.position.y + alien.imgAliens[alien.typeAlien - 1].height},
                                    6));

        lastAlienShootTime = GetTime();
    }
}

void GameState::checkFOrCollision()
{
    // Spaceship Lasers

    for (auto &laser : SpaceShip::lasers)
    {
        auto it = aliens.begin();
        while (it != aliens.end())
        {
            if (CheckCollisionRecs(it->getRect(), laser.getRect()))
            {
                PlaySound(alienHitSound);

                if (it->typeAlien == 1)
                {
                    score += 100;
                }
                else if (it->typeAlien == 2)
                {
                    score += 200;
                }
                else if (it->typeAlien == 3)
                {
                    score += 300;
                }
                it = aliens.erase(it);
                laser.active = false;
            }
            else
            {
                ++it;
            }
        }

        for (auto &obstacle : obstacles)
        {
            auto it = obstacle.blocks.begin();
            while (it != obstacle.blocks.end())
            {
                if (CheckCollisionRecs(it->getRect(), laser.getRect()))
                {
                    it = obstacle.blocks.erase(it);
                    laser.active = false;
                }
                else
                {
                    ++it;
                }
            }
        }

        if (CheckCollisionRecs(boos.getRect(), laser.getRect()))
        {
            boos.alive = false;
            laser.active = false;
            score += 500;
            PlaySound(alienHitSound);
        }
    }

    // Alien Lasers

    for (auto &laser : aliensLaser)
    {
        if (CheckCollisionRecs(laser.getRect(), SpaceShip::getRect()))
        {
            PlaySound(spaceShipHitSound);
            laser.active = false;
            lives--;
            if (lives == 0)
                gameOver();
        }

        for (auto &obstacle : obstacles)
        {
            auto it = obstacle.blocks.begin();
            while (it != obstacle.blocks.end())
            {
                if (CheckCollisionRecs(it->getRect(), laser.getRect()))
                {
                    it = obstacle.blocks.erase(it);
                    laser.active = false;
                }
                else
                {
                    ++it;
                }
            }
        }
    }

    // Alien Collision with Obstacle

    for (auto &alien : aliens)
    {
        for (auto &obstacle : obstacles)
        {
            auto it = obstacle.blocks.begin();
            while (it != obstacle.blocks.end())
            {
                if (CheckCollisionRecs(it->getRect(), alien.getRect()))
                {
                    it = obstacle.blocks.erase(it);
                }
                else
                {
                    it++;
                }
            }
        }

        if (CheckCollisionRecs(alien.getRect(), SpaceShip::getRect()))
        {
            PlayMusicStream(endGameMusic);

            gameOver();
        }
    }
}

void GameState::gameOver()
{
    running = false;
}

string GameState::FormatWithLeadingZeros(int number, int width)
{
    string numberText = to_string(number);
    int leadingZeros = width - numberText.length();
    return numberText = string(leadingZeros, '0') + numberText;
}

void GameState::drawTheInterFace()
{
    Rectangle rec = {10, 10, 780, 780};
    DrawRectangleRoundedLines(rec, 0.18f, 20, yellow);
    DrawLineEx({25, 730}, {775, 730}, 3, yellow);
    DrawTextEx(font, "SCORE", {50, 15}, 34, 2, yellow);
    string scoreText = FormatWithLeadingZeros(score, 5);
    DrawTextEx(font, scoreText.c_str(), {50, 40}, 34, 2, yellow);
}

void GameState::drawLevel()
{

    DrawTextEx(font, "Level 01", {570, 740}, 34, 2.0f, yellow);
}

void GameState::drawAndUpdateLives()
{
    float x = 50.0;
    for (int i = 0; i < lives; i++)
    {
        DrawTextureV(SpaceShip::imgSpaceShip, {x, 735}, WHITE);
        x += 70;
    }
}

void GameState::initGame()
{

    obstacles = createObstacle();
    aliens = createAlien();
    aliensDirection = 1;
    lastAlienShootTime = 0.0;
    boosTimeLastSpawn = 0.0;
    boosAlienDelay = GetRandomValue(5, 10);
    lives = 3;
    score = 0;
    running = true;
}

void GameState::reGame()
{
    SpaceShip::resetSpaceShip();
    aliens.clear();
    aliensLaser.clear();
    obstacles.clear();
}