#include "button.hpp"

Button::Button(const char* imgPath, Vector2 imgPosition)
{
    texture = LoadTexture(imgPath);
    position = imgPosition;
}

Button::~Button()
{
    // UnloadTexture(playButton);
    // UnloadTexture(exitButton);
    UnloadTexture(texture);
}

void Button::buttonDraw()
{
    DrawTexture(texture, position.x - texture.width / 2, position.y - texture.height / 2, WHITE);
    // DrawTexture(playButton, position.x, position.y -80, WHITE);
    // DrawTexture(exitButton, position.x + 4, position.y + 80,  WHITE);
}

bool Button::isPressed(Vector2 mousePos, bool mousePressed)
{
    Rectangle rect = {position.x - texture.width / 2, position.y - texture.height / 2, float(texture.width), float(texture.height)};

    if (CheckCollisionPointRec(mousePos, rect) && mousePressed)
    {
        return true;
    }
    return false;
}
