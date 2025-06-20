#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Pun1 {
    int puntos;
    sf::Font font;
    sf::Text texto;
public:
    Pun1() : puntos(0) {
        font.loadFromFile("Minecraft.ttf"); // Asegúrate de tener Minecraft.ttf en el directorio de ejecución
        texto.setFont(font);
        texto.setCharacterSize(32);
        texto.setFillColor(sf::Color::White);
        texto.setPosition(10, 10);
        texto.setString("Puntos: 0");
    }
    void sumarPunto() {
        puntos++;
        texto.setString("Puntos: " + std::to_string(puntos));
    }
    int getPuntos() const { return puntos; }
    sf::Text& getTexto() { return texto; }
    void actualizarTexto() {
        texto.setString("Puntos: " + std::to_string(puntos));
    }
};

