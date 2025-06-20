#pragma once
#include <SFML/Graphics.hpp>

class Pe {
private:
    sf::CircleShape shape;
public:
    Pe() {
        shape.setRadius(25.f);
        shape.setFillColor(sf::Color::White);
        shape.setPosition(0.f, 0.f);
    }

    sf::CircleShape& getShape() {
        return shape;
    }
};
