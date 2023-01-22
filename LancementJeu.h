#ifndef LANCEMENT_JEU_H
#define LANCEMENT_JEU_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"
#include "Arrow.h"
#include "Screen.h"

class LancementJeu : public Screen
{
private:
    sf::Texture* backgroundTexture;
    sf::Sprite* background;
    sf::Event event;
    std::vector<Button*> buttons;
    Arrow* arrow;
    int currButton;
public:
    LancementJeu(sf::RenderWindow*);
    ~LancementJeu();
    int run();
    void drawButtons();
    void drawArrow();
};

#endif
