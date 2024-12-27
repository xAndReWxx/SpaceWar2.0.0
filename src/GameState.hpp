#pragma once
#include "Game.hpp"


class GameState {
public:
    virtual void handleInput(Game& game) = 0;
    virtual void update(Game& game) = 0;
    virtual void draw(Game& game) = 0;
    virtual ~GameState() {}
};