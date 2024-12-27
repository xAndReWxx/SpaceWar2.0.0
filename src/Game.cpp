#include "Game.hpp"

Game::Game()
{
    currentState = new MainMenuState();
}

Game::~Game()
{
    delete currentState;
}


void Game::changeState(State* newState)
{
    delete currentState;
    currentState = newState;
}

void Game::handleInputGame()
{
    currentState -> handleInput(*this);
}

void Game::updateGame()
{
    currentState -> update(*this);

}

void Game::drawGame()
{
    currentState -> draw(*this);

}

