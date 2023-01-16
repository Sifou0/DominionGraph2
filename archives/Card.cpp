#include "Card.hpp"

Card::Card(int nb) 
{
    this->shape = new sf::RectangleShape(sf::Vector2f(220,360));
    this->texture = nullptr;
    this->nb = nb;
}

Card::~Card()
{
    delete this;
}

void Card::loadTexture(sf::Texture* t)
{
    int x = nb%7,y = nb/7;
    texture = t;
    shape->setTexture(texture);
    shape->setTextureRect(sf::IntRect(x*(t->getSize().x/7),y*(t->getSize().y/5),t->getSize().x/7,t->getSize().y/5));
}

sf::RectangleShape* Card::getDrawable()
{
    return this->shape;
}