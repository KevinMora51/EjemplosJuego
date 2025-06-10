#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

// este es el main
int main()
{
    sf::RenderWindow w(sf::VideoMode(800, 600), "DVD xd");

    sf::Texture t;
    if (!t.loadFromFile("./assets/images/DVD.png"))
    {
        // no jalo
        return 123;
    }
    sf::Sprite s(t);

    // variables random
    float a = 50, b = 50;
    float dx = 1, dy = 0.7;
    auto ws = w.getSize();
    auto sb = s.getLocalBounds();

    while (w.isOpen())
    {
        sf::Event e;
        while (w.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                w.close();
            }
        }

        // mover
        a += dx;
        b += dy;

        // rebote loco
        if (a < 0) {
            a = 0;
            dx = -dx;
        }
        if (a + sb.width > ws.x) {
            a = ws.x - sb.width;
            dx = -dx;
        }
        if (b < 0) {
            b = 0;
            dy = -dy;
        }
        if (b + sb.height > ws.y) {
            b = ws.y - sb.height;
            dy = -dy;
        }

        s.setPosition(a, b);

        w.clear();
        w.draw(s);
        w.display();
        sf::sleep(sf::milliseconds(5)); // zzz
    }
    return 7;
}