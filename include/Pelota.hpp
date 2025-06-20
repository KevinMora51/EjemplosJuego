#pragma once
#include <SFML/Graphics.hpp>

class Pelota {
    sf::CircleShape& circ;
    float dx, dy;
public:
    Pelota(sf::CircleShape& c) : circ(c), dx(0.3f), dy(0.3f) {}

    void mover() { circ.move(dx, dy); }
    void invertirDx() { dx = -dx; }
    void invertirDy() { dy = -dy; }
    void setPos(float x, float y) { circ.setPosition(x, y); }
    sf::CircleShape& get() { return circ; }
    sf::FloatRect getBounds() const { return circ.getGlobalBounds(); }
    float getX() const { return circ.getPosition().x; }
    float getY() const { return circ.getPosition().y; }
    float getR() const { return circ.getRadius(); }
};