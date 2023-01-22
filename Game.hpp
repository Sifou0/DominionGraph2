#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "Carte.h"
#include "CarteVictoire.h"
#include "CarteReversed.h"
#include "PlateformeGame.h"
#include "Arrow.h"
#include "Deck.h"
#include "Screen.h"
#include "Joueur.h"
#include "Button.h"

class Game : public Screen
{
private:
    sf::Event event;
    Arrow* arrow;
    Deck* monDeck;
    Deck* achatRoyaume;
    Deck* reversedCartes;
    sf::Font* font;
    std::vector<sf::Text*> texts;
    static Joueur* currJoueur;
    Button* buttonFinTour;
    PlateformeGame* back;
    static std::vector<Joueur*> m_list_joueur;
    int currId;
    int nextScreen;
    int nbr_joueur;
    static int nbr_achat;
    static int nbr_action;
    static int piece_posee;
    static int end_game;
    bool phase; //0 -> action 1 -> achat
    void handleKeys();
    void handleEvents();
    void initCards();
    void drawMonDeck();
    void carteOnTop();
    void drawReversed();
    void drawAchatRoyaume();
    void handleMouse();
    void drawFinTour();
    void setGame();
    void incrementEndGame();
    bool gameIsEnd();
    void phaseAchat();
    void playCarte();
    void drawTexts();
    void phaseAction();
public:
    Game(sf::RenderWindow*,int);
    ~Game();
    int run();
    static void setAction(int);
    static void increment_achat();
    static void increment_action();
    static void ajouterPiece(int);
    static void add_to_player_discard(Carte&);
    static void putonHand(Carte&);
};

#endif