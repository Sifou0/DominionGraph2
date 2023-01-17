#include "Arrow.h"

Arrow::Arrow()
{
    texture = new sf::Texture();
    texture->loadFromFile("assets/Icons/arrow.png");
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