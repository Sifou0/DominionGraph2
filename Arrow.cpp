#include "Arrow.h"

Arrow::Arrow()
{
    texture = new sf::Texture();
    texture->loadFromFile("assets/Icons/arrow.png");
    shape = new sf::RectangleShape(sf::Vector2f(20,20));
    shape->setTexture(texture);
}

Arrow::Arrow(int i)
{
    texture = new sf::Texture();
    switch (i)
    {
    case 1:
        texture->loadFromFile("assets/Icons/arrowD.png");
        break;
    case 2:
        texture->loadFromFile("assets/Icons/arrowG.png");
        break;
    default:
        texture->loadFromFile("assets/Icons/arrow.png");
        break;
    }
    shape = new sf::RectangleShape(sf::Vector2f(20,20));
    shape->setTexture(texture);
}

sf::RectangleShape* Arrow::getDrawable()
{
    return shape;
}

Arrow::~Arrow()
{
}