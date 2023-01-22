#include "Deck.h"

Deck::Deck()
{
    monDeck = std::vector<Carte*>();
    carteTexture = new sf::Texture();
    carteTexture->loadFromFile("assets/Cards/Carte.png");
}

Deck::Deck(std::vector<Carte*> v)
{
    monDeck = v;
    carteTexture = new sf::Texture();
    carteTexture->loadFromFile("assets/Cards/Carte.png");
}

Deck::~Deck()
{

}

void Deck::addToDeck(Carte* c)
{
    monDeck.push_back(c);
}

void Deck::clearDeck()
{
    monDeck.clear();
}

void Deck::setDeck(std::vector<Carte*> v)
{
    this->monDeck = v;
}

std::vector<Carte*> Deck::getCartes()
{
    return this->monDeck;
}

void Deck::loadTextures()
{
    for(Carte* c : monDeck)
    {
        c->loadTexture(carteTexture);
    }
}