#include "Carte.h"
#include <iostream>

class CarteReversed : public Carte
{
public:
    CarteReversed();
    ~CarteReversed();
    void afficher() const;
    void bref_description() const;
    Carte::TypeCarte getCardType() const;
};