#ifndef ARROW_H
#define ARROW_H
#include <SFML/Graphics.hpp>


class Arrow
{
private:
    sf::Texture* texture;
    sf::RectangleShape* shape;
public:
    Arrow();
    ~Arrow();
    Arrow(int);
    sf::RectangleShape* getDrawable();
};




#endif