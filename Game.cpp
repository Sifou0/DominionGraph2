#include "Game.hpp"
#include <vector>

int Game::nbr_achat = 1;
int Game::nbr_action = 1;
int Game::end_game = 0;
int Game::piece_posee = 0;
bool Game::effect = 0;
Carte* Game::carteP = new CarteRoyaume();
Joueur* Game::currJoueur = new Joueur("premier");

void Game::setAction(int n)
{
    nbr_action = n;
}

void Game::increment_achat() {
	nbr_achat++;
}

void Game::increment_action() {
	nbr_action++;
}

void Game::ajouterPiece(int value_coin) 
{
	piece_posee += value_coin;
}

void Game::incrementEndGame() {
	end_game++;
}

void Game::enableEffect()
{
    effect = true;
}

void func_village(Joueur j, std::vector<Joueur*>list_joueur)
{

	//Game::setAction(2);

}


void func_vi(Joueur j, std::vector<Joueur*>list_joueur)
{
	j.pickFromDeckToHand(1);
	Game::setAction(3);
    
}

void func_festival(Joueur j , std::vector<Joueur*>list_joueur)
{

	Game::setAction(2);
	Game::increment_achat();
	Game::ajouterPiece(2);
    Game::enableEffect();
}

void func_buch(Joueur j , std::vector<Joueur*>list_joueur)
{
	Game::increment_achat();
	Game::ajouterPiece(2);
    Game::enableEffect();
}

void func_marche(Joueur j , std::vector<Joueur*>list_joueur)
{
	
	Game::increment_action();
	Game::increment_achat();
	Game::ajouterPiece(1);
    Game::enableEffect();
}
void func_attelier(Joueur j , std::vector<Joueur*>list_joueur)
{
	
	Game::ajouterPiece(4);

}

void func_vassal(Joueur j , std::vector<Joueur*>list_joueur)
{
	j.from_top_deck_to_discard();
	Game::ajouterPiece(2);

}

void func_forge(Joueur j , std::vector<Joueur*>list_joueur)
{

	j.pickFromDeckToHand(3);

}
std::vector<Joueur*> Game::m_list_joueur = std::vector<Joueur*>();
std::vector<CarteTresor*> pile_cuivre = std::vector<CarteTresor*>(47, new CarteTresor(CarteTresor::CUIVRE));
std::vector<CarteTresor*> pile_argent = std::vector<CarteTresor*>(41 , new CarteTresor(CarteTresor::ARGENT));
std::vector<CarteTresor*> pile_or = std::vector<CarteTresor*>(31, new CarteTresor(CarteTresor::OR));
std::vector<CarteVictoire*> pile_domaine = std::vector<CarteVictoire*>(9,new CarteVictoire(CarteVictoire::DOMAINE));
std::vector<CarteVictoire*> pile_duchet = std::vector<CarteVictoire*>(9,new CarteVictoire(CarteVictoire::DUCHET));
std::vector<CarteVictoire*> pile_province = std::vector<CarteVictoire*>(9,new CarteVictoire(CarteVictoire::PROVINCE));
std::vector<CarteVictoire*> pile_cursed = std::vector<CarteVictoire*>(9,new CarteVictoire(CarteVictoire::MALEDICTION));
std::vector<CarteRoyaume*> carte_royaume_1 = std::vector<CarteRoyaume*>(11, new CarteRoyaume(3,"Village" , CarteRoyaume::TypeRoyaume::ACTION_ACTION , func_village));
std::vector<CarteRoyaume*> carte_royaume_2 = std::vector<CarteRoyaume*>(11, new CarteRoyaume(5, "Marche", CarteRoyaume::TypeRoyaume::ACTION_ACTION, func_village));
std::vector<CarteRoyaume*> carte_royaume_3 = std::vector<CarteRoyaume*>(11, new CarteRoyaume(3, "Bucheron", CarteRoyaume::TypeRoyaume::ACTION_ACTION, func_village));
std::vector<CarteRoyaume*> carte_royaume_4 = std::vector<CarteRoyaume*>(11, new CarteRoyaume(3, "Atelier", CarteRoyaume::TypeRoyaume::ACTION_ACTION, func_village));
std::vector<CarteRoyaume*> carte_royaume_5 = std::vector<CarteRoyaume*>(11, new CarteRoyaume(4, "Forgeron", CarteRoyaume::TypeRoyaume::ACTION_ACTION, func_village));
std::vector<CarteRoyaume*> carte_royaume_6 = std::vector<CarteRoyaume*>(11, new CarteRoyaume(5, "Festival", CarteRoyaume::TypeRoyaume::ACTION_ACTION, func_village));




bool Game::gameIsEnd()
{
	if (pile_province.size() == 1) {
		return true;
	}
	if(currJoueur->getVictory_value() == 30)
	{
		return true;
	}
	if(end_game == 3)
	{
		return true;
	}

	return false;
}

Game::Game(sf::RenderWindow* w,int nbJ) : Screen(w), nbr_joueur(nbJ)
{
    bg = new sf::Texture();
    bgS = new sf::Sprite();
    bg->loadFromFile("assets/Images/backgame.jpg");
    bgS->setTexture(*bg);
    // monDeck = PlateformeGame::getActuelJoueur().getHandCartes();
    arrow = new Arrow();
    monDeck = new Deck();
    achatRoyaume = new Deck();
    reversedCartes = new Deck();
    font = new sf::Font();
    font->loadFromFile("assets/Fonts/Adonais.ttf");
    texts = std::vector<sf::Text*>{new sf::Text("Credits : 0", *font,30), new sf::Text("Action : 1",*font,30),new sf::Text("Phase : Action",*font,30), new sf::Text("Achats : 1",*font,30)};
    buttonFinTour = new Button("Fin de Tour");
    //back = new PlateformeGame();
    //monDeck->setDeck(std::vector<Carte*>{new CarteTresor(CarteTresor::CUIVRE),new CarteTresor(CarteTresor::ARGENT),new CarteTresor(CarteTresor::OR),new CarteVictoire(CarteVictoire::DOMAINE),new CarteVictoire(CarteVictoire::DOMAINE),new CarteVictoire(CarteVictoire::DOMAINE),new CarteVictoire(CarteVictoire::DOMAINE),new CarteVictoire(CarteVictoire::DOMAINE),new CarteVictoire(CarteVictoire::DOMAINE),new CarteVictoire(CarteVictoire::DOMAINE),new CarteVictoire(CarteVictoire::DOMAINE),new CarteVictoire(CarteVictoire::DOMAINE)});
    achatRoyaume->setDeck(std::vector<Carte*>{new CarteRoyaume("Village",3),new CarteRoyaume("Bucheron",3),new CarteRoyaume("Atelier",3),new CarteRoyaume("Cave",2),new CarteRoyaume("Chapelle",2),new CarteTresor(CarteTresor::CUIVRE), new CarteTresor(CarteTresor::ARGENT),new CarteTresor(CarteTresor::OR),new CarteRoyaume("Forgeron",4),new CarteRoyaume("Marche",5),new CarteRoyaume("Mine",5),new CarteRoyaume("Sorciere",5),new CarteRoyaume("Renovation",4),new CarteVictoire(CarteVictoire::DOMAINE),new CarteVictoire(CarteVictoire::DUCHET),new CarteVictoire(CarteVictoire::PROVINCE),new CarteVictoire(CarteVictoire::MALEDICTION)});
    //this->initArrow();
    currId = 0;
    nextScreen = 1;
    phase = 0; //0 -> action 1 -> achat
    this->setGame();
    this->initCards();
}

void Game::add_to_player_discard(Carte& carte)
{
	if (carte.getCardType() == Carte::ROYAUME)
	{
		// cout << "Il s'agit dune carte royaume" << endl;
		// cout << "On execute donc la carte " << endl;
		CarteRoyaume& carte_r = dynamic_cast<CarteRoyaume&>(carte);
		carte_r.execute_action(*currJoueur, m_list_joueur);
	}
	else
	{
		// cout << "Carte envoyee dans le discard du joueur actuel" << endl;
	}
}

Game::~Game()
{
    delete window;
    delete this;
}

void Game::setGame()
{
    for (int i = 0; i < nbr_joueur; i++) 
    {
		m_list_joueur.push_back(new Joueur("Joueur " + (i+1)));
	}
    currJoueur = m_list_joueur[0];
    monDeck->setDeck(currJoueur->getHandCartes());
    for (int i = 0; i < 11; i++)
	{
	
		carte_royaume_1[i]->attribute_fun(func_vi , *currJoueur);
		carte_royaume_2[i]->attribute_fun(func_marche , *currJoueur);
		carte_royaume_3[i]->attribute_fun(func_buch , *currJoueur);
		carte_royaume_4[i]->attribute_fun(func_attelier, *currJoueur);
		carte_royaume_5[i]->attribute_fun(func_forge, *currJoueur);
		carte_royaume_6[i]->attribute_fun(func_festival, *currJoueur);
	}
}

void Game::drawMonDeck() // prend 50% de l'ecran en largeur et seulement 50% de la carte est visible en hauteur
{
    int window_x = window->getSize().x;
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
    
    nextScreen = 0;
    while (window->isOpen())
    {
        window->clear();
        window->draw(*bgS);
        monDeck->setDeck(currJoueur->getHandCartes());
        this->initCards();
        if(nextScreen != 0) return nextScreen;
        //std::cout << currId << std::endl;
        this->handleEvents();
        this->drawMonDeck();
        this->drawReversed();
        this->drawAchatRoyaume();
        this->drawFinTour();
        this->drawTexts();
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
            monDeck->setDeck(currJoueur->getHandCartes());
            this->drawMonDeck();
            break;
        case sf::Keyboard::Right:
            if(currId < monDeck->getCartes().size()-1) currId++;
            monDeck->setDeck(currJoueur->getHandCartes());
            this->drawMonDeck();
            break;
        case sf::Keyboard::Escape:
            nextScreen = 1;
        case sf::Keyboard::Return:
            std::cout << "Play carte\n";
            this->playCarte();
            monDeck->setDeck(currJoueur->getHandCartes());
            this->drawMonDeck();
            break;
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
        case sf::Event::MouseButtonPressed:
            this->handleMouse();
        default:
            break;
        }
    }
}

void Game::playCarte()
{
    if(!phase) //Action
    {
        if(currJoueur->isRoyaume(currId) && nbr_action > 0)
        {
           
            dynamic_cast<CarteRoyaume*>(currJoueur->getHandCartes()[currId])->execute_action(*currJoueur,m_list_joueur);
            nbr_action--;
            monDeck->setDeck(currJoueur->getHandCartes());
            this->initCards();
            this->drawMonDeck();
            std::cout << monDeck->getCartes().size() << std::endl;
            currJoueur->addOntable(currId);
            currId = 0;
        }
    }
    else //Achat
    {
        if(currJoueur->isTresor(currId) && nbr_achat > 0)
        {
            dynamic_cast<CarteTresor*>(currJoueur->getHandCartes()[currId])->effect_card();
            currJoueur->addOntable(currId);
            currId = 0;
            //::cout << piece_posee << std::endl;
            //window->clear();
        }
    }
    if((phase && nbr_achat == 0) || (!phase && nbr_action == 0)) phase = !phase;
}

void Game::phaseAchat()
{
    if(!effect) this->nbr_achat = 1;
    effect = false;
    this->piece_posee = 0; ///// !!!!!!!!!!!!!
    currJoueur->from_deck_to_discard();
    currJoueur->setDiscard();
    monDeck->setDeck(currJoueur->getHandCartes());
    this->drawMonDeck();
}

void Game::phaseAction()
{
    this->nbr_action = 1;
    //std::cout << monDeck->getCartes().size() << std::endl;
    monDeck->setDeck(currJoueur->getHandCartes());
    this->drawMonDeck();
}

void Game::drawAchatRoyaume()
{
    for(int i = 0 ; i < achatRoyaume->getCartes().size() ; ++i)
    {
        achatRoyaume->getCartes()[i]->getDrawable()->setPosition(0.26*window->getSize().x + (i%8) * (achatRoyaume->getCartes()[i]->getDrawable()->getSize().x + 10) , 0.4*window->getSize().y + ((i/8) * (achatRoyaume->getCartes()[i]->getDrawable()->getSize().y + 10)));
        window->draw(*achatRoyaume->getCartes()[i]->getDrawable());
    }
}

void Game::initCards()
{
    reversedCartes->addToDeck(new CarteReversed());
    reversedCartes->addToDeck(new CarteReversed());
    reversedCartes->loadTextures();
    // std::cout << reversedCartes->getCartes()[0]->getTextureId() << std::endl;
    // std::cout << monDeck.size() << std::endl;
    monDeck->loadTextures();
    achatRoyaume->loadTextures();
}

void Game::putonHand(Carte &carte)
{
	if (carte.getCardType() == Carte::VICTOIRE) {
		if(nbr_action > 0)
		{
        CarteVictoire& carte_v = dynamic_cast<CarteVictoire&>(carte);
		carte_v.effect_card(*currJoueur);
        
		currJoueur->addCardOnHand(carte);	
        }
	}
	else {
		currJoueur->addCardOnHand(carte);
	}
    nbr_action--;

}

void Game::putToDiscard(Carte &carte)
{
    currJoueur->addToDiscard(carte);
}

void Game::handleMouse()
{
    monDeck->setDeck(currJoueur->getHandCartes());
    if(phase)
    {
        for(Carte* c : achatRoyaume->getCartes())
        {
            if(c->getDrawable()->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window))))
            {
                if(piece_posee >= c->getCarteCost() && nbr_achat > 0)
                {
                    if (c->getCardType() == Carte::VICTOIRE)
                    {
                        if(dynamic_cast<CarteVictoire*>(c)->getTypeVictoire() == CarteVictoire::DOMAINE)
                        {
                            if(pile_domaine.size() > 1)
                            {
                                putToDiscard(*pile_domaine.back());
                                pile_domaine.pop_back();
                            }
                            if (pile_domaine.size() == 1) 
                            {
			                    incrementEndGame();
		                    }
                        }
                        if(dynamic_cast<CarteVictoire*>(c)->getTypeVictoire() == CarteVictoire::DUCHET)
                        {
                            if(pile_duchet.size() > 1)
                            {
                                putToDiscard(*pile_duchet.back());
                                pile_duchet.pop_back();
                            }
                            if (pile_duchet.size() == 1) 
                            {
			                    incrementEndGame();
		                    }
                        }
                        if(dynamic_cast<CarteVictoire*>(c)->getTypeVictoire() == CarteVictoire::PROVINCE)
                        {
                            if(pile_province.size() > 1)
                            {
                                putToDiscard(*pile_province.back());
                                pile_province.pop_back();
                            }
                            if (pile_province.size() == 1) 
                            {
			                    incrementEndGame();
		                    }
                        }
                    }
                    else if(c->getCardType() == Carte::TRESOR)
                    {
                        if(dynamic_cast<CarteTresor*>(c)->getTypeTresor() == CarteTresor::CUIVRE)
                        {
                            if(pile_cuivre.size() > 1)
                            {
                                putToDiscard(*pile_cuivre.back());
                                pile_cuivre.pop_back();
                            }
                            if (pile_cuivre.size() == 1) 
                            {
			                    incrementEndGame();
		                    }
                        }
                        if(dynamic_cast<CarteTresor*>(c)->getTypeTresor() == CarteTresor::ARGENT)
                        {
                            if(pile_argent.size() > 1)
                            {
                                putToDiscard(*pile_argent.back());
                                pile_argent.pop_back();
                            }
                            if (pile_argent.size() == 1) 
                            {
			                    incrementEndGame();
		                    }
                        }
                        if(dynamic_cast<CarteTresor*>(c)->getTypeTresor() == CarteTresor::OR)
                        {
                            if(pile_or.size() > 1)
                            {
                                putToDiscard(*pile_or.back());
                                pile_or.pop_back();
                            }
                            if (pile_or.size() == 1) 
                            {
			                    incrementEndGame();
		                    }
                        }
                    }
                    else if(c->getCardType() == Carte::ROYAUME)
                    {
                        CarteRoyaume* cR = dynamic_cast<CarteRoyaume*>(c);
                        if(cR->getName() == "Village" && carte_royaume_1.size() > 0)
                        {
                            //std::cout << "Village\n";
                            putToDiscard(*carte_royaume_1.back());
                            carte_royaume_1.pop_back();
                        }
                        else if(cR->getName() == "Marche" && carte_royaume_2.size() > 0)
                        {
                            putToDiscard(*carte_royaume_2.back());
                            carte_royaume_2.pop_back();
                        }
                        else if(cR->getName() == "Bucheron" && carte_royaume_3.size() > 0)
                        {
                            putToDiscard(*carte_royaume_3.back());
                            carte_royaume_3.pop_back();
                        }
                        else if(cR->getName() == "Atelier" && carte_royaume_4.size() > 0)
                        {
                            putToDiscard(*carte_royaume_4.back());
                            carte_royaume_4.pop_back();
                        }
                        else if(cR->getName() == "Forgeron" && carte_royaume_5.size() > 0)
                        {
                            putToDiscard(*carte_royaume_5.back());
                            carte_royaume_5.pop_back();
                        }
                        else if(cR->getName() == "Festival" && carte_royaume_6.size() > 0)
                        {
                            putToDiscard(*carte_royaume_6.back());
                            carte_royaume_6.pop_back();
                        }
                    }
                    piece_posee -= c->getCarteCost();
                    nbr_achat--;
                    if(nbr_achat == 0)
                    {
                        phase = !phase;
                        this->phaseAchat();
                    }
                }
            }
        }
    }
    if(buttonFinTour->getDrawable()->getGlobalBounds().contains(sf::Vector2f(sf::Mouse::getPosition(*window))))
    {
        monDeck->setDeck(currJoueur->getHandCartes());
        if(phase)
        {
            this->phaseAchat();
        }
        else
        {
            this->phaseAction();
            monDeck->setDeck(currJoueur->getHandCartes());
            this->drawAll();
        }
        phase = !phase;
    }
    this->drawAll();
}


void Game::drawFinTour()
{
    buttonFinTour->getDrawable()->setScale(0.2,0.2);
    buttonFinTour->setPosition(window->getSize().x - 180 - (0.5 * buttonFinTour->getDrawable()->getGlobalBounds().width),window->getSize().y - 100 - (0.2 * buttonFinTour->getDrawable()->getGlobalBounds().height));
    window->draw(*buttonFinTour->getDrawable());
    buttonFinTour->getText()->setCharacterSize(40);
    buttonFinTour->getText()->move(-60,10);
    window->draw(*buttonFinTour->getText());
}

void Game::drawTexts()
{
    texts[0]->setString("Credits : " + std::to_string(piece_posee));
    texts[1]->setString("Actions : " + std::to_string(nbr_action));
    texts[3]->setString("Achats : " + std::to_string(nbr_achat));
    if(phase == 0) texts[2]->setString("Phase : Action");
    else  texts[2]->setString("Phase : Achat");
    for(int i = 0 ; i < texts.size() ; ++i)
    {
        texts[i]->setPosition(10,window->getSize().y - ((i+1) * texts[0]->getGlobalBounds().height) - 10);
    }
    for(sf::Text* t : texts) window->draw(*t);
}

void Game::drawAll()
{
    this->initCards();
    window->clear();
    this->drawAchatRoyaume();
    this->drawFinTour();
    this->drawMonDeck();
    this->drawReversed();
    this->drawTexts();
    window->display();
}