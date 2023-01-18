#include "Button.h"

Button::Button()
{
    texture = new sf::Texture();
    texture->loadFromFile("assets/Icons/button.png");
    sprite = new sf::Sprite(*texture);
    text = new sf::Text();
    font = new sf::Font();
    // font->loadFromFile();
}

Button::~Button()
{

}

sf::Sprite* Button::getDrawable()
{
    return sprite;
}

sf::Vector2u Button::getSize()
{
    return texture->getSize();
}