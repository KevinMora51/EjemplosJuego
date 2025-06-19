#include <SFML/Graphics.hpp>
#include "../include/GameWindow.hpp"
#include <string>
#include "../include/PJ1.hpp"
#include "../include/PJ2.hpp"
#include "../include/Pe.hpp"


sf::Vector2i dir(0, 0);


void ChangeDir(bool useWASD)
{
    if(!useWASD)
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && dir.y!=1)     dir = {0, -1};
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && dir.y!=-1)  dir = {0, 1};
    }
    else
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) && dir.y!=1)  dir = {0, -1};
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) && dir.y!=-1) dir = {0, 1};
    }
}

int main()
{
    GameWindow window(800, 600, "SFML Window");

    PJ1 pj1; 
    sf::RectangleShape& rectangle = pj1.getShape();

    PJ2 pj2;
    sf::RectangleShape& rectangle2 = pj2.getShape();

    Pe pe;
    sf::CircleShape& circle = pe.getShape();

    float velocidad = 0.5f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            rectangle.move(0, -velocidad);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            rectangle.move(0, velocidad);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            rectangle2.move(0, -velocidad);
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            rectangle2.move(0, velocidad);

        window.clear();
        window.draw(rectangle);
        window.draw(rectangle2);
        window.draw(circle); // Dibuja el círculo de Pe
        window.display();
    }

    return 0;
}
