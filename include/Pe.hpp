#include <SFML/Graphics.hpp>
class Pe
{
private:
    sf::CircleShape circle;
public:
    Pe() : circle(38) { 
        circle.setFillColor(sf::Color::Green);
        circle.setPosition(400, 300);
    }

    sf::CircleShape& getShape() {
        return circle;
    }
};
