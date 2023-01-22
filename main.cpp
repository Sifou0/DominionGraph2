#include "Menu.h"
#include "Game.hpp"
#include "LancementJeu.h"
#include "SFML/Graphics.hpp"
#include <vector>

int main()
{
    int currentScreen = 1;
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(1600,1200),"Dominion");
    Game* game = new Game(window,1);
    Menu* menu = new Menu(window);
    // LancementJeu* lj = new LancementJeu(window);
    std::vector<Screen*> screens {game,menu};
    while (window->isOpen())
    {
        currentScreen = screens[currentScreen]->run();
        // lj->run();
    }
    
    return 0;
}