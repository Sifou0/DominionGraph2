#include <iostream>
#include "CarteRoyaume.h"
#include "Joueur.h"
#include "PlateformeGame.h"

using namespace std;

CarteRoyaume::CarteRoyaume() 
{
	m_type_carte = Carte::ROYAUME;
	m_type_cart_royaume = TypeRoyaume::ACTION_ACTION;
	m_carte_cost = 2;
	m_description_carte = "Carte tranquille posey";
	m_nom_carte = "Bucheron";
	
}

  CarteRoyaume::CarteRoyaume(int cost, string name_card, TypeRoyaume typecart, void(&func)(Joueur, std::vector<Joueur*>))
{
	m_nom_carte = name_card;
	m_type_carte = Carte::ROYAUME;
	m_type_cart_royaume = typecart;
	m_carte_cost = cost;
	effect = &func;
	if(m_nom_carte == "Village") 
	{
		//std::cout << "vill" << std::endl;
		this->setTextureId(25);
		//std::cout << this->getTextureId() << std::endl;
	}
	else if(m_nom_carte == "Bucheron") this->setTextureId(33);
}



  void CarteRoyaume::attribute_fun( void(&func)(Joueur, std::vector<Joueur*>) , Joueur j)
  {
	effect = &func;

  }
 /*  void CarteRoyaume::testshowAdressEffect()const
  {
	  cout << "Ladresse de la function effect est " << effect << endl;
  }*/
  void CarteRoyaume::execute_action(Joueur &j ,vector<Joueur*>list_j)
  {
	  this->effect(j ,list_j);
  }


void CarteRoyaume::afficher()const{

	cout << "Il sagit dune carte royaume" << endl;
}

void CarteRoyaume::bref_description()const {
	cout << "bientot" << endl;
};

Carte::TypeCarte CarteRoyaume::getCardType()const 
{
	return m_type_carte;
}

void CarteRoyaume::effect_card()
{
	cout << "Une action sera activee " << endl;

	PlateformeGame::decrement_action();
}

string CarteRoyaume::getName()const
{
	return m_nom_carte;
}

CarteRoyaume::~CarteRoyaume()
{
	delete &effect;
}
