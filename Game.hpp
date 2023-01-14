#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Card.hpp"

class Game
{
private:
    sf::RenderWindow* window;
    sf::Event event;
    sf::Texture* cardsTexture;
    std::vector<Card*> cards; //0 : mon deck, 1 : pile gauche
public:
    Game();
    ~Game();
    void run();
    void handleEvents();
    void initCards();
};

#endif