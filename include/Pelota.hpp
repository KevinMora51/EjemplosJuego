#pragma once
#include <SFML/Graphics.hpp>

class Pelota {
    sf::CircleShape& circ;
    float dx = 0.3f, dy = 0.3f;
public:
    Pelota(sf::CircleShape& c) : circ(c) {}
    void mover() { circ.move(dx, dy); }
    void invertirDx() { dx = -dx; }
    void invertirDy() { dy = -dy; }
    sf::CircleShape& get() { return circ; }
};