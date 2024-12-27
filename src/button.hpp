#pragma once
#include "Positions.hpp"

class Button : public Positions{
protected:
    Texture2D texture;
public:
    Button(const char* imgPath, Vector2 imgPosition);
    ~Button();
    void buttonDraw();
    bool isPressed(Vector2 mousePos, bool mousePressed);
};