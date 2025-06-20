#pragma once
#include <SFML/Graphics.hpp>
class PJ2
{
private:
    sf::RectangleShape rectangle2;
public:
    PJ2() : rectangle2(sf::Vector2f(35, 250)) {
        rectangle2.setFillColor(sf::Color::White);
        rectangle2.setPosition(20, 150);
    }

    sf::RectangleShape& getShape() {
        return rectangle2;
    }
};