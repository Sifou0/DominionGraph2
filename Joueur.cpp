#include <iostream>
#include "Joueur.h"
#include "Carte.h"
#include "CarteVictoire.h"
#include <algorithm>
#include <random>
#include "CarteRoyaume.h"
#include "Game.hpp"

std::random_device rd;
std::mt19937 g(rd());

using namespace std;
template<typename T>
void pop_front(std::vector<T>& v)
{
	if (v.size() > 0) {
		v.erase(v.begin());
	}
}

bool Joueur:: hasTresor()const 
{
	for (int i = 0; i < m_hand.size(); i++) {
		if (m_hand[i]->getCardType() == Carte::TRESOR) {
			return true;
			
		}
	}
	return false;
}

bool Joueur::hasRoyaume()const
{
	for (int i = 0; i < m_hand.size(); i++) {
		if (m_hand[i]->getCardType() == Carte::ROYAUME) {
			return true;

		}
	}
	return false;
}
bool Joueur::hasTypeCarte(Carte::TypeCarte type_cart)const
{
	for (int i = 0; i < m_hand.size(); i++) {
		if (m_hand[i]->getCardType() == type_cart) {
			return true;

		}
	}
	return false;
}


bool Joueur::isTresor(int position)const
{
	if (isGoodIndice(position , m_hand)) {
		return m_hand[position]->getCardType() == CarteTresor::TRESOR;
	}
	else {
		return false;
	}
 	
}

bool Joueur::isRoyaume(int position)const
{
	if (isGoodIndice(position, m_hand)) {
		return m_hand[position]->getCardType() == CarteTresor::ROYAUME;
	}
	else {
		return false;
	}
}

bool Joueur::isTypeRequested(int position , Carte::TypeCarte type_carte)const
{
	if (isGoodIndice(position, m_hand)) {
		return m_hand[position]->getCardType() == type_carte;
	}
	else {
		return false;
	}
}

bool Joueur::isGoodIndice(int position, std::vector<Carte*>cartes)const
{
	
 	if(position < m_hand.size() && position >= 0)
	{
		return true;
	}
	else {
		cout << "It's not a good indice \n";
		return false;
	}

}

vector<Carte*> Joueur::getHandCartes()const
{
	return m_hand;
}

Joueur::Joueur(string pseudo)
{
	m_pseudo = pseudo;
	m_victory_value = 0;
	m_deck = vector<Carte*>();
	m_discard = vector<Carte*>();
	m_hand = vector<Carte*>();
	


	for (int i = 0; i < 7; i++) {
		m_deck.push_back(new CarteTresor());
	}
	for (int i = 0; i < 3; i++) {
		m_victory_value++;
		m_deck.push_back(new CarteVictoire());
	}
	
	shuffle(m_deck.begin() , m_deck.end() , rd);
	for (int i = 0 ; i <5; i++) {
		m_hand.push_back(m_deck[0]);
		pop_front(m_deck);
	}
	
}

string Joueur::getPseudo()const 
{
	return m_pseudo;

}

void Joueur::presenter()const {
	cout << "Je suis un joueur deominion et mon pseudo est "<< m_pseudo << endl;
	cout << "Nombre de points : " << m_victory_value << endl;
}



// void Joueur::useCartePiece(CarteTresor carte_tresor)
// {

// 	PlateformeGame::utiliserPiece(carte_tresor.getCarteValue());
// 	PlateformeGame::decrement_achat();
// }
void Joueur::addOntable(int position_carte) {
	m_discard.push_back(m_hand[position_carte]);
	m_hand.erase(m_hand.begin() + position_carte);
}

void Joueur::setVictoryVal(int val)
{
	m_victory_value += val;
}

//  void Joueur::useCarteAction(CarteRoyaume carte_royaume)
// {

// 	PlateformeGame::decrement_action();
// }

void Joueur::addCardOnHand(Carte& carte)
{
	m_hand.push_back(&carte);
}

void Joueur::addToDiscard(Carte& carte)
{
	m_discard.push_back(&carte);
}

void Joueur::carteMain()const
{
	if(m_hand.size() >0)
	{
		for (int i = 0; i < m_hand.size(); i++) 
		{
			m_hand[i]->bref_description();
		}
	}
	else {
		cout << "Main est vide " << endl;
	}
}

void Joueur::showDeck()const
{
	if(m_deck.size()>0){
		for(int i = 0 ; i < m_deck.size() ; i++)
		{
			m_deck[i]->bref_description();
		}
	}else{
		cout << "Cest vide" << endl;
	}
}

void Joueur::showDiscard()const
{
	if(m_discard.size() == 0)
	{
		for (int i = 0; i < m_discard.size(); i++) {
			m_discard[i]->bref_description();
		}
	}else
	{
		cout << "discard est vide" << endl;
	}
	
}

void Joueur::setDiscard(){
	//std::cout << m_discard.size() << std::endl;
	if(m_deck.size()>=5){
		m_hand.insert(m_hand.begin(), m_deck.begin(), m_deck.begin() + 5);
		m_deck.erase(m_deck.begin() , m_deck.begin() + 5);
	}

	else {
		shuffle(m_discard.begin(), m_discard.end(),rd);
		m_deck.insert(m_deck.begin(), m_discard.begin(), m_discard.end());
		m_discard.clear();
		m_hand.insert(m_hand.begin(), m_deck.begin(), m_deck.begin() + 5);
		m_deck.erase(m_deck.begin(), m_deck.begin() + 5);
	}
}

void Joueur::showcart_type_tresor() const {
	
	for (int i = 0; i < m_hand.size(); i++) {
		if (m_hand[i]->getCardType() == Carte::TypeCarte::TRESOR) {
			cout << "Position " << i << " ";
			m_hand[i]->bref_description();

		}
			
	}
	if (hasTresor() == false ) {
		cout << "Il n'y a pas de tresor pour lachat" << endl;
	}
}

void Joueur::showcart_type_royaume()const {

	for (int i = 0; i < m_hand.size(); i++) {
		if (m_hand[i]->getCardType() == Carte::TypeCarte::ROYAUME) {
			cout << "Position " << i << " ";
			m_hand[i]->bref_description();

		}

	}
	if (hasTresor() == false) {
		cout << "Il n'y a pas de tresor pour lachat" << endl;
	}

}
void Joueur::showcart_type_carte(Carte::TypeCarte type_cart)const {

	for (int i = 0; i < m_hand.size(); i++) {
		if (m_hand[i]->getCardType() == type_cart) {
			cout << "Position " << i << " ";
			m_hand[i]->bref_description();

		}

	}
	

}

void Joueur::pickFromDeckToHand(int nbr_carte)
{
	if(m_deck.size()>= nbr_carte)
	{
		//std::cout << "Here1" << std::endl;
		for (int i = 0; i < nbr_carte ; i++) {
			m_hand.push_back(m_deck.back());
			//m_deck.back()->afficher();
			m_deck.pop_back();
		}
		// std::cout << m_hand.size() << std::endl;
	}
	else
	{
		//std::cout << "Here2" << std::endl;
		shuffle(m_discard.begin(), m_discard.end(),rd);
		m_deck.insert(m_deck.begin(), m_discard.begin(), m_discard.end());
		m_discard.clear();
		for (int i = 0; i < nbr_carte ; i++) {
			m_hand.push_back(m_deck.back());
			//m_deck.back()->afficher();
			m_deck.pop_back();
		}
		// std::cout << m_hand.size() << std::endl;
	}
	

}

// void Joueur:: from_deck_to_place(int position)
// {
// 	PlateformeGame::add_to_trash(*m_deck[position]);
// 	m_deck.erase(m_deck.begin() + position, m_deck.end() - position);
// }


// void Joueur:: from_top_deck_to_trash()
// {
	
// 	PlateformeGame::add_to_trash(*m_deck.back());
// 	m_deck.pop_back();
// }

void Joueur::from_top_deck_to_discard()
{
	Game::add_to_player_discard(*m_deck.back());
	m_discard.push_back(m_deck.back());
	m_deck.pop_back();
}

void Joueur::from_deck_to_discard()
{
	for(int i = 0 ; i < m_hand.size() ; i++)
	{
		m_discard.push_back(m_hand[i]);
	}
	m_hand.clear();
}

int Joueur::getVictory_value()const
{
	return m_victory_value;
}

Joueur::~Joueur() 
{

}