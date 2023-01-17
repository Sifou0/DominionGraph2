#include "Deck.h"

Deck::Deck()
{
    monDeck = std::vector<Carte*>();
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