#ifndef DECK_H
#define DECK_H
#include "Carte.h"
#include <vector>

class Deck
{
private:
    std::vector<Carte*> monDeck;
    sf::Texture* carteTexture;
public:
    Deck();
    ~Deck();
    void addToDeck(Carte*);
    void clearDeck();
    void setDeck(std::vector<Carte*>);
    std::vector<Carte*> getCartes();
    void loadTextures();
};

#endif