#pragma once
#include <SFML/Graphics.hpp>

class Jugador {
    sf::RectangleShape& rect;
public:
    Jugador(sf::RectangleShape& r) : rect(r) {}
    void moverArriba(float v) { rect.move(0, -v); }
    void moverAbajo(float v) { rect.move(0, v); }
    sf::RectangleShape& get() { return rect; }
    sf::FloatRect getBounds() const { return rect.getGlobalBounds(); }
};
