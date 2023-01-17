#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Carte.h"
#include "CarteVictoire.h"
#include "CarteReversed.h"
#include "PlateformeGame.h"
#include "Arrow.h"
#include "Deck.h"
#include "Screen.h"

class Game : public Screen
{
private:
    sf::Event event;
    Arrow* arrow;
    Deck* monDeck;
    Deck* reversedCartes;
    int currId;
    int nextScreen;
    void handleKeys();
    void handleEvents();
    void initCards();
    void drawMonDeck();
    void carteOnTop();
    void drawReversed();

public:
    Game(sf::RenderWindow*);
    ~Game();
    int run();
};

#endif