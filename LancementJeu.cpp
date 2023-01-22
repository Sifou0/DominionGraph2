#include "LancementJeu.h"

LancementJeu::LancementJeu(sf::RenderWindow* w) : Screen(w)
{
    backgroundTexture = new sf::Texture();
    backgroundTexture->loadFromFile("assets/Images/bg.jpg");
    background = new sf::Sprite(*backgroundTexture);
    buttons = std::vector<Button*> { new Button("1",1),new Button("2",1),new Button("3",1),new Button("4",1)};
    arrow = new Arrow();
    currButton = 1;
}

LancementJeu::~LancementJeu() {}

int LancementJeu::run()
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
                    if(currButton < 2) return currButton;
                    else window->close();
                }
                if(event.key.code == sf::Keyboard::Left)
                {
                    if(currButton > 1) currButton--;
                }
                if(event.key.code == sf::Keyboard::Right)
                {
                    if(currButton < buttons.size()-1) currButton++;
                }
            }
        }
        window->clear();
        window->draw(*background);
        this->drawButtons();
        this->drawArrow();
        window->display();
    }
    return 0;
}

void LancementJeu::drawButtons()
{
    for(int i = 0 ; i < buttons.size() ; ++i)
    {
        buttons[i]->getDrawable()->setScale(0.35,0.35);
        buttons[i]->setPosition(0.25*i*window->getSize().x / 2 - buttons[i]->getDrawable()->getGlobalBounds().width/2 ,window->getSize().y / 2 - buttons[i]->getDrawable()->getGlobalBounds().height/2);
        buttons[i]->getDrawable()->move(window->getSize().x*0.3,0);
        buttons[i]->getText()->setPosition(buttons[i]->getDrawable()->getPosition());
        window->draw(*buttons[i]->getDrawable());
        window->draw(*buttons[i]->getText());
    }
}

void LancementJeu::drawArrow()
{
    arrow->getDrawable()->setPosition(buttons[currButton]->getDrawable()->getPosition());
    arrow->getDrawable()->move(buttons[currButton]->getDrawable()->getGlobalBounds().width/2,buttons[currButton]->getDrawable()->getGlobalBounds().height);
   // arrow->getDrawable()->move(15,0);
    window->draw(*arrow->getDrawable());
}