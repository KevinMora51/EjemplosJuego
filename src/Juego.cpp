#include <SFML/Graphics.hpp>
#include "../include/GameWindow.hpp"
#include "../include/PJ1.hpp"
#include "../include/PJ2.hpp"
#include "../include/Pe.hpp"
#include "../include/Velc.hpp"

sf::Vector2i dir(0, 0);

int main()
{
    GameWindow window(800, 600, "SFML Window");

    PJ1 pj1;
    sf::RectangleShape& rect1 = pj1.getShape();

    PJ2 pj2;
    sf::RectangleShape& rect2 = pj2.getShape();

    Pe pe;
    sf::CircleShape& circle = pe.getShape();

    Velc vel; 

    float startX = window.getSize().x / 2.0f - circle.getRadius();
    float startY = window.getSize().y / 2.0f - circle.getRadius();
    circle.setPosition(startX, startY);

    bool esperando = false;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
            if (event.type == sf::Event::Closed)
                window.close();

        if (!esperando) {
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) rect1.move(0, -0.5f);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) rect1.move(0, 0.5f);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) rect2.move(0, -0.5f);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) rect2.move(0, 0.5f);

            circle.move(vel.getDx(), vel.getDy());

            if (circle.getGlobalBounds().intersects(rect1.getGlobalBounds()) ||
                circle.getGlobalBounds().intersects(rect2.getGlobalBounds()))
                vel.invertirDx();

            float x = circle.getPosition().x;
            float y = circle.getPosition().y;
            float r = circle.getRadius();
            if (y <= 0 || y + 2*r >= window.getSize().y)
                vel.invertirDy();

            if (x + 2*r < 0 || x > window.getSize().x)
                esperando = true;
        } else {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
                circle.setPosition(startX, startY);
                esperando = false;
            }
        }

        window.clear();
        window.draw(rect1);
        window.draw(rect2);
        window.draw(circle);
        window.display();
    }
    return 0;
}