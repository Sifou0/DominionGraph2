#include "Button.h"

Button::Button()
{
    buttonText = "";
    texture = new sf::Texture();
    texture->loadFromFile("assets/Icons/button.png");
    sprite = new sf::Sprite(*texture);
    text = new sf::Text();
    font = new sf::Font();
    font->loadFromFile("assets/Fonts/Adonais.ttf");
    text->setFont(*font);
    text->setFillColor(sf::Color::Black);
    text->setCharacterSize(60);
}

Button::Button(std::string s)
{
    buttonText = s;
    texture = new sf::Texture();
    texture->loadFromFile("assets/Icons/button.png");
    //std::cout << "lll" << std::endl;
    sprite = new sf::Sprite(*texture);
    text = new sf::Text();
    font = new sf::Font();
    font->loadFromFile("assets/Fonts/Adonais.ttf");
    text->setString(buttonText);
    text->setFont(*font);
    text->setFillColor(sf::Color::Black);
    text->setCharacterSize(60);
}

Button::~Button()
{

}

sf::Sprite* Button::getDrawable()
{
    return sprite;
}

sf::Vector2u Button::getSize()
{
    return texture->getSize();
}

sf::Text* Button::getText()
{
    return text;
}

int Button::getNbChar()
{
    return buttonText.size();
}