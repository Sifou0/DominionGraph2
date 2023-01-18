#ifndef MENU_H
#define MENU_H
#include "Screen.h"
#include "Button.h"
#include "Arrow.h"
#include <vector>

class Menu : public Screen
{
private:
    sf::Texture* backgroundTexture;
    sf::Sprite* background;
    sf::Event event;
    std::vector<Button*> buttons;
    std::vector<Arrow*> arrows;
    int currButton;
public:
    Menu(sf::RenderWindow*);
    ~Menu();
    int run();
    void drawButtons();
    void drawArrows();
};


#endif