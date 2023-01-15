#ifndef DEF_CARTE
#define DEF_CARTE
#include <string>
#include <SFML/Graphics.hpp>

class Carte
{
private:
	sf::RectangleShape* shape;
	sf::Texture* texture;
	int nb;
public:
	enum TypeCarte
	{
		VICTOIRE,TRESOR,ROYAUME
	};

	virtual void afficher() const = 0;
	virtual void bref_description() const = 0;
	virtual TypeCarte getCardType() const = 0;
	virtual void effect_card() ;
	int getCarteCost() const;
	int getTextureId();
	Carte();
	virtual ~Carte();
	void loadTexture(sf::Texture*);
    sf::RectangleShape* getDrawable();
	
protected:
	TypeCarte m_type_carte;
	int m_carte_cost;
	int textureId;
};

#endif