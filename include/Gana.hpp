#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Gana {
    std::string ganador;
public:
    Gana() : ganador("") {}

    void verificarGanador(float x, float radio, float anchoVentana) {
        // Si la pelota sale por la derecha, gana PJ1
        if (x - radio > anchoVentana) {
            ganador = "Gana PJ1";
        }
    }

    bool hayGanador() const { return !ganador.empty(); }
    std::string getMensaje() const { return ganador; }
    void reset() { ganador = ""; }
};
        texto.setString("Gana: " + ganador);
    }
    bool hayGanador() const { return !ganador.empty(); }
    sf::Text& getTexto() { return texto; }
    void reset() {
        ganador = "";
        texto.setString("");
    }
    bool fuenteOk() const { return fuenteCargada; }
};
