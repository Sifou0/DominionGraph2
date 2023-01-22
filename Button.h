#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
class Button
{
private:
    std::string buttonText;
    sf::Texture* texture;
    sf::Sprite* sprite;
    sf::Text* text;
    sf::Font* font;
public:
    Button();
    Button(std::string);
    Button(std::string,int);
    ~Button();
    sf::Sprite* getDrawable();
    sf::Vector2u getSize();
    sf::Text* getText();
    int getNbChar();
    void setPosition(float,float);
};

#endif