#include "Carte.h"
#include <vector>
#include <iostream>
using namespace std;


Carte::Carte() {
	this->shape = new sf::RectangleShape(sf::Vector2f(110,180));
    this->texture = nullptr;
}



void Carte::effect_card() {

}

int Carte::getCarteCost() const{
	return m_carte_cost;
}

Carte::~Carte()
{
	
}

void Carte::setTextureId(int i) { textureId = i; }

int Carte::getTextureId() { return textureId; }

void Carte::loadTexture(sf::Texture* t)
{
    int x = textureId%7,y = textureId/7;
    this->texture = t;
    shape->setTexture(t);
    shape->setTextureRect(sf::IntRect(x*(t->getSize().x/7),y*(t->getSize().y/5),t->getSize().x/7,t->getSize().y/5));
}

sf::RectangleShape* Carte::getDrawable()
{
    return this->shape;
}