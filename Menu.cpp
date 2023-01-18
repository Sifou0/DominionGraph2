#include "Menu.h"

Menu::Menu(sf::RenderWindow* w) : Screen(w)
{
    backgroundTexture = new sf::Texture();
    backgroundTexture->loadFromFile("assets/Images/bg.jpg");
    background = new sf::Sprite(*backgroundTexture);
    buttons = std::vector<Button*> {new Button("Jouer"), new Button("En ligne"), new Button("Quitter")};
    arrows = std::vector<Arrow*> {new Arrow(2),new Arrow(1)};
    currButton = 0;
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
                if(event.key.code == sf::Keyboard::Up)
                {
                    if(currButton > 0) currButton--;
                }
                if(event.key.code == sf::Keyboard::Down)
                {
                    if(currButton < buttons.size()-1) currButton++;
                }
            }


        }
        window->clear();
        window->draw(*background);
        this->drawButtons();
        this->drawArrows();
        window->display();
    }
    return 0;
    
}

void Menu::drawButtons()
{
    for(int i = 0 ; i < buttons.size() ; ++i)
    {
        buttons[i]->getDrawable()->setPosition(window->getSize().x/2 - 0.2 * buttons[i]->getSize().x / 2, window->getSize().y*0.3 + i * window->getSize().y * 0.15);
        buttons[i]->getDrawable()->setScale(0.2,0.2);
        buttons[i]->getText()->setPosition(buttons[i]->getDrawable()->getPosition().x + buttons[i]->getSize().x * 0.2 * 0.5 - (buttons[i]->getNbChar() * buttons[i]->getText()->getCharacterSize())*0.222,buttons[i]->getDrawable()->getPosition().y + buttons[i]->getSize().y * 0.035 * 0.5);
        window->draw(*(buttons[i]->getDrawable()));
        window->draw(*(buttons[i]->getText()));
    }
}

void Menu::drawArrows()
{
    for(int i = 0 ; i < arrows.size() ; i++)
    {
        arrows[i]->getDrawable()->setPosition(buttons[currButton]->getDrawable()->getPosition());
        arrows[i]->getDrawable()->move(0,buttons[0]->getSize().y*0.16*0.5);
    }
    arrows[0]->getDrawable()->move(buttons[0]->getSize().x*0.1845,0);
    arrows[0]->getDrawable()->move(15,0);
    arrows[1]->getDrawable()->move(-15,0);
    window->draw(*arrows[0]->getDrawable());
    window->draw(*arrows[1]->getDrawable());
}