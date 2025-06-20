#pragma once
#include <SFML/Graphics.hpp>
#include "../include/PJ1.hpp"
#include "../include/PJ2.hpp"
#include "../include/Pe.hpp"
#include "../include/Jugador.hpp"
#include "../include/Pelota.hpp"

class Juego {
private:
    sf::RenderWindow window;
    PJ1 pj1;
    PJ2 pj2;
    Pe pe;
    Jugador jugador1;
    Jugador jugador2;
    Pelota pelota;
    float startX, startY;
    bool esperando;

public:
    Juego() :
        window(sf::VideoMode(800, 600), "SFML Window"),
        pj1(), pj2(), pe(),
        jugador1(pj1.getShape()), 
        jugador2(pj2.getShape()),
        pelota(pe.getShape()),
        esperando(false)
    {
        startX = window.getSize().x / 2.0f - pelota.getR();
        startY = window.getSize().y / 2.0f - pelota.getR();
        pelota.setPos(startX, startY);
    }

    void procesarEventos() {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();
    }

    void actualizar() {
        if (!esperando) {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) jugador1.moverArriba(0.5f);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) jugador1.moverAbajo(0.5f);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) jugador2.moverArriba(0.5f);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) jugador2.moverAbajo(0.5f);

            pelota.mover();

            if (pelota.getBounds().intersects(jugador1.getBounds()) ||
                pelota.getBounds().intersects(jugador2.getBounds()))
                pelota.invertirDx();

            float x = pelota.getX();
            float y = pelota.getY();
            float r = pelota.getR();
            if (y <= 0 || y + 2*r >= window.getSize().y)
                pelota.invertirDy();

            if (x + 2*r < 0 || x > window.getSize().x)
                esperando = true;
        } else {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                pelota.setPos(startX, startY);
                esperando = false;
            }
        }
    }

    void dibujar() {
        window.clear();
        window.draw(jugador1.get()); 
        window.draw(jugador2.get());
        window.draw(pelota.get());
        window.display();
    }

    void buclePrincipal() {
        while (window.isOpen()) {
            procesarEventos();
            actualizar();
            dibujar();
        }
    }
};