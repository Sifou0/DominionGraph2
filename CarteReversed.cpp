#include "CarteReversed.h"

CarteReversed::CarteReversed()
{
    this->setTextureId(34);
    this->m_type_carte = Carte::REVERSED;
}

CarteReversed::~CarteReversed()
{
}

void CarteReversed::afficher()const{

	std::cout << "Il sagit dune carte retourne" << std::endl;
}

void CarteReversed::bref_description() const {
	std::cout << "bientot" << std::endl;
};

Carte::TypeCarte CarteReversed::getCardType()const 
{
	return m_type_carte;
}
