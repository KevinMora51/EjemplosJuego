#include <SFML/Graphics.hpp>
 int main()
 {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Image");

    sf::Texture texture;
    if (!texture.loadFromFile("./assets/images/DVD.png"))
    {
        
        return -1;
    }
    sf::Sprite sprite(texture);

    float x =100;
    float y=100;

    float dx = 0.1; // velocidad más lenta
    float dy = 0.1; // velocidad más lenta

   
    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                
                window.close();
            }
        }

        x += dx;
        y += dy;

        // Obtén los límites actualizados del sprite en la posición nueva
        sprite.setPosition(x, y);
        sf::FloatRect bounds = sprite.getGlobalBounds();

        if (x < 0)
        {
            x = 0;
            dx = -dx;
        }

        if (x + bounds.width > window.getSize().x)
        {
            x = window.getSize().x - bounds.width;
            dx = -dx;
        }
        if (y < 0)
        {
            y = 0;
            dy = -dy;
        }
        if (y + bounds.height > window.getSize().y)
        {
            y = window.getSize().y - bounds.height;
            dy = -dy;
        }
        window.clear();

        sprite.setPosition(x, y); // Asegura la posición correcta

        window.draw(sprite);

        
        window.display();
    }
    return 0;
 }