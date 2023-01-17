#ifndef SCREEN_H
#define SCREEN_H
#include <SFML/Graphics.hpp>

class Screen
{
protected:
    sf::RenderWindow* window;
public:
    Screen(sf::RenderWindow*);
    ~Screen();
    virtual int run() = 0;
};




#endif