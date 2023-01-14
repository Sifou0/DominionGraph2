#include "Game.hpp"

Game::Game() 
{
    window = new sf::RenderWindow(sf::VideoMode(800,600),"Dominion");
    cards = std::vector<Card*>();
    cardsTexture = new sf::Texture();
    cardsTexture->loadFromFile("assets/Cards/Carte.png");
    this->initCards();
}

Game::~Game()
{
    delete window;
    delete this;
}

void Game::run()
{
    while (window->isOpen())
    {
        this->handleEvents();
        for(Card* c : cards)
        {
            window->draw(*(c->getDrawable()));
        }
        window->display();
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
        default:
            break;
        }
    }
}

void Game::initCards()
{
    // for(int i = 0 ; i < 1 ; ++i)
    // {
        Card* curr = new Card(7);
        curr->loadTexture(cardsTexture);
        this->cards.push_back(curr);
    //}
}