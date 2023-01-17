#include "Menu.h"
#include "Game.hpp"
#include "SFML/Graphics.hpp"
#include <vector>

int main()
{
    int currentScreen = 0;
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1600,1200),"Dominion");
    Game* game = new Game(window);
    Menu* menu = new Menu(window);
    std::vector<Screen*> screens {menu,game};
    while (window->isOpen())
    {
        currentScreen = screens[currentScreen]->run();
    }
    
    return 0;
}