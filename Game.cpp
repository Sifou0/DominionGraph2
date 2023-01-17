#include "Game.hpp"
#include <vector>

Game::Game(sf::RenderWindow* w) : Screen(w)
{

    // monDeck = PlateformeGame::getActuelJoueur().getHandCartes();
    arrow = new Arrow();
    // monDeck = 
    monDeck = new Deck();
    reversedCartes = new Deck();
    monDeck->setDeck(std::vector<Carte*> {new CarteVictoire(CarteVictoire::DOMAINE),new CarteVictoire(CarteVictoire::DOMAINE),new CarteVictoire(CarteVictoire::DOMAINE),new CarteVictoire(CarteVictoire::DOMAINE),new CarteVictoire(CarteVictoire::DOMAINE),new CarteVictoire(CarteVictoire::DOMAINE),new CarteVictoire(CarteVictoire::DOMAINE),new CarteVictoire(CarteVictoire::DOMAINE),new CarteVictoire(CarteVictoire::DOMAINE),new CarteVictoire(CarteVictoire::DOMAINE),new CarteVictoire(CarteVictoire::DOMAINE)});
    this->initCards();
    //this->initArrow();
    currId = 0;
    nextScreen = 1;
    //std::cout << window << std::endl;
}

Game::~Game()
{
    delete window;
    delete this;
}

void Game::drawMonDeck() // prend 50% de l'ecran en largeur et seulement 50% de la carte est visible en hauteur
{
    int window_x = window->getSize().x;
    window->clear();
    int monDeckSize = monDeck->getCartes().size();
    if(monDeckSize > 0)
    {
        int offX = window_x*(1./monDeckSize)*0.5;
        if(monDeckSize % 2 == 0)
        {
            for(int i = 0 ; i < monDeckSize ; ++i)
            {
                monDeck->getCartes()[i]->getDrawable()->setPosition((window_x/2),0);
            }
            int cpt = 1;
            for(int i = monDeckSize/2-1; i > -1 ; --i)
            {
                monDeck->getCartes()[i]->getDrawable()->move(offX*cpt*(-1),0);
                cpt++;
            }
            cpt = 1;
            for(int i = monDeckSize/2+1; i < monDeckSize ; ++i)
            {
                monDeck->getCartes()[i]->getDrawable()->move(offX*cpt,0);
                cpt++;
            }
        }
        else
        {   
            for(int i = 0 ; i < monDeckSize ; ++i)
            {
                monDeck->getCartes()[i]->getDrawable()->setPosition((window_x/2)-(monDeck->getCartes()[monDeckSize/2]->getDrawable()->getSize().x/2),0);
            }
            int cpt = 1;
            for(int i = monDeckSize/2-1; i > -1 ; --i)
            {
                monDeck->getCartes()[i]->getDrawable()->move(offX*cpt*(-1),0);
                cpt++;
            }
            cpt = 1;
            for(int i = monDeckSize/2+1; i < monDeckSize ; ++i)
            {
                monDeck->getCartes()[i]->getDrawable()->move(offX*cpt,0);
                cpt++;
            }
        }
        this->carteOnTop();
        for(Carte* c : monDeck->getCartes()) window->draw(*(c->getDrawable()));
        this->window->draw(*arrow->getDrawable());
    }
}

void Game::drawReversed()
{
    reversedCartes->getCartes()[0]->getDrawable()->setPosition(10,10);
    reversedCartes->getCartes()[1]->getDrawable()->setPosition(window->getSize().x - reversedCartes->getCartes()[1]->getDrawable()->getSize().x - 10 ,10);
    for(Carte* c : reversedCartes->getCartes()) window->draw(*(c->getDrawable()));
}

int Game::run()
{
    nextScreen = 1;
    while (window->isOpen())
    {
        if(nextScreen != 1) return nextScreen;
        //std::cout << currId << std::endl;
        //PlateformeGame::StartGame();
        this->handleEvents();
        this->drawMonDeck();
        this->drawReversed();
        window->display();
    }
    return nextScreen;
}

void Game::carteOnTop()
{
    monDeck->getCartes()[currId]->getDrawable()->move(0,monDeck->getCartes()[currId]->getDrawable()->getSize().y);
    arrow->getDrawable()->setPosition(monDeck->getCartes()[currId]->getDrawable()->getPosition().x + monDeck->getCartes()[currId]->getDrawable()->getSize().x/2 - arrow->getDrawable()->getSize().x/2,monDeck->getCartes()[currId]->getDrawable()->getSize().y+190);
    // currArrow->setPosition(monDeck[currId]->getDrawable()->getPosition());
}

void Game::handleKeys()
{
    switch (this->event.key.code)
    {
    case sf::Keyboard::Left:
        if(currId > 0) currId--;
        break;
    case sf::Keyboard::Right:
        if(currId < monDeck->getCartes().size()-1) currId++;
        break;
    case sf::Keyboard::Escape:
        nextScreen = 0;
    default:
        break;
    }
}

void Game::handleEvents()
{
    while(this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
        case sf::Event::Closed:
            this->window->close();
            break;
        case sf::Event::KeyPressed:
            this->handleKeys();
            break;
        default:
            break;
        }
    }
}

void func_vill(Joueur j, std::vector<Joueur*>list_joueur)
{
	//j.pickFromDeckToHand(1);
	//PlateformeGame::setAction(2);

}

void Game::initCards()
{
    reversedCartes->addToDeck(new CarteReversed());
    reversedCartes->addToDeck(new CarteReversed());
    reversedCartes->loadTextures();
    // std::cout << reversedCartes->getCartes()[0]->getTextureId() << std::endl;
    // std::cout << monDeck.size() << std::endl;
    monDeck->loadTextures();
}