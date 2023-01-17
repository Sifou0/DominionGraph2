#ifndef MENU_H
#define MENU_H
#include "Screen.h"

class Menu : public Screen
{
private:
    sf::Texture* backgroundTexture;
    sf::Sprite* background;
    sf::Event event;
public:
    Menu(sf::RenderWindow*);
    ~Menu();
    int run();
};


#endif