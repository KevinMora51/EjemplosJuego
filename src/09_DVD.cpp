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

    float x =50;
    float y=50;

    float dx = 0.5; 
    float dy = 0.5; 

   
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
        window.clear(sf::Color::White); 

        sprite.setPosition(x, y);

        window.draw(sprite);

        
        window.display();
        
    }
    return 0;
 }