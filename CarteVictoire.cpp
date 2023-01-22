#include <iostream>
#include "CarteVictoire.h"
#include "Joueur.h"

using namespace std;

string enum_to_string(CarteVictoire::TypeVictoire victoire) {
	switch (victoire)
	{
	case CarteVictoire::DOMAINE:
		return "Domaine";
		break;
	case CarteVictoire::DUCHET:
		return "Duchet";
		break;
	case CarteVictoire::PROVINCE:
		return "Province";
		break;
	case CarteVictoire::MALEDICTION:
		return "Malediction";
		break;
	default:
		cout << "Error" << endl;
		return "Domaine";
		break;
	}
}

int CarteVictoire::getValueVictoire()const {
	return m_valeur_victoire;
}

 CarteVictoire::TypeVictoire CarteVictoire::getTypeVictoire() const{
 
	 return m_typevictoire;
 }

CarteVictoire::CarteVictoire() {
	this->setTextureId(14);
	m_type_carte = Carte::VICTOIRE;
	m_typevictoire = CarteVictoire::DOMAINE;
	m_valeur_victoire = 1;
	m_carte_cost = 2;
	setTextureId(14);
}

CarteVictoire::CarteVictoire(TypeVictoire typevictoire):m_typevictoire(typevictoire)
{

	m_type_carte = Carte::VICTOIRE;
	switch (typevictoire)
	{
	case CarteVictoire::DOMAINE:
		m_valeur_victoire = 1;
		m_carte_cost = 2;
		this->setTextureId(14);
		break;
	case CarteVictoire::DUCHET:
		m_valeur_victoire = 3;
		m_carte_cost = 5;
		this->setTextureId(11);
		break;
	case CarteVictoire::PROVINCE:
		m_valeur_victoire = 6;
		m_carte_cost = 8;
		this->setTextureId(10);
		break;
	case CarteVictoire::MALEDICTION:
		m_valeur_victoire = -1;
		m_carte_cost = 0;
		this->setTextureId(9);
		break;
	default:
		cout << "ERRORR" << endl;
		m_valeur_victoire = 1;
		break;
	}
	//std::cout << textureId << std::endl;
}

void CarteVictoire::afficher() const{
	

	cout << "Il s'agit dune carte victoire" << endl;
	cout << "Je suis de type " << enum_to_string(m_typevictoire) << " et je vaux " << m_valeur_victoire << " victoire(s)" << endl;

}

void CarteVictoire::bref_description()const {

	cout << "Type victoire " << enum_to_string(m_typevictoire) << " valeur " << m_valeur_victoire << endl;
}

Carte::TypeCarte CarteVictoire::getCardType()const
{
	return m_type_carte;
}

void CarteVictoire::effect_card(Joueur &joueur) 
{
	joueur.setVictoryVal(m_valeur_victoire );
	cout << "Rien de particulier sur la table " << endl;
	
};


void CarteVictoire::beenTrashed(Joueur &joueur)const 
{
	if(m_typevictoire == CarteVictoire::MALEDICTION)
	{
		joueur.setVictoryVal(abs(m_valeur_victoire));
	}
	else {
		joueur.setVictoryVal(-m_valeur_victoire);
	}

}

CarteVictoire::~CarteVictoire()
{

}