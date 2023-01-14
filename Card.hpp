#ifndef CARD_H
#define CARD_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Card
{
    private:
        sf::RectangleShape* shape;
        sf::Texture* texture;
        int nb;
    public:
        Card(int);
        ~Card();
        void loadTexture(sf::Texture*);
        sf::RectangleShape* getDrawable();
};

#endif