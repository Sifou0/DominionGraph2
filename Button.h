#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>


class Button
{
private:
    sf::Texture* texture;
    sf::Sprite* sprite;
    sf::Text* text;
    sf::Font* font;
public:
    Button();
    ~Button();
    sf::Sprite* getDrawable();
    sf::Vector2u getSize();
};

#endif