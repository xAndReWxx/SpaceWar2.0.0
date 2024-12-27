#pragma once
#include "State.hpp"
#include "MainMenuState.hpp"
class Game{
private:
    State *currentState;
public:
    Game();
    ~Game();
    void handleInputGame ();
    void updateGame();
    void drawGame();
    void changeState(State* newState);
};
