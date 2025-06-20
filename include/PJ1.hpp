#pragma once
#include <SFML/Graphics.hpp>
class PJ1
{
private:
    sf::RectangleShape rectangle;
public:
    PJ1() : rectangle(sf::Vector2f(35, 250)) {
        rectangle.setFillColor(sf::Color::White);
        rectangle.setPosition(750, 200);
    }

    sf::RectangleShape& getShape() {
        return rectangle;
    }
};




