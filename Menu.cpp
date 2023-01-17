#include "Menu.h"

Menu::Menu(sf::RenderWindow* w) : Screen(w)
{
    backgroundTexture = new sf::Texture();
    backgroundTexture->loadFromFile("assets/Images/bg.jpg");
    background = new sf::Sprite(*backgroundTexture);
}

Menu::~Menu()
{

}

int Menu::run()
{
    while (window->isOpen())
    {
        while (window->pollEvent(event))
		{
			// Window closed
			if (event.type == sf::Event::Closed)
			{
				window->close();
			}
            if(event.type == sf::Event::KeyPressed)
            {
                if(event.key.code == sf::Keyboard::Return)
                {
                    return 1;
                }
            }


        }
        window->clear();
        window->draw(*background);
        window->display();
    }
    return 0;
    
}

