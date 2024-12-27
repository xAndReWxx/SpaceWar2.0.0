#pragma once
#include "Block.hpp"
#include "Positions.hpp"
#include <vector>
using namespace std;

class Obstacle {
private:

public:
    Vector2 position;
    Obstacle(Vector2 position = {0, 0});
    void drawObstacle();
    vector<Block> blocks;
    //VECTOR 2D
    vector<vector<int>> grid;
};










