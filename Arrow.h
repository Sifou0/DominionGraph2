#ifndef ARROW_H
#define ARROW_H
#include <SFML/Graphics.hpp>


class Arrow
{
private:
    sf::Texture* texture;
    sf::RectangleShape* shape;
public:
    Arrow();
    ~Arrow();
    sf::RectangleShape* getDrawable();
};

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


#endif