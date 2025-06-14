#include <SFML/Graphics.hpp>

int main()
{
    // Crear una ventana
    sf::RenderWindow window(sf::VideoMode(800, 600), "Sprite Animado");

    // Cargar la imagen desde un archivo
    sf::Texture texture;
    if (!texture.loadFromFile("assets/images/Punk_Run.png"))
    {
        // Manejo de error si no se puede cargar la imagen
        return -1;
    }

    // Crear un sprite y asignarle la textura
    sf::Sprite sprite(texture);
    sprite.setPosition(400, 300);

    sf::Clock clock;
    float frameTime = 0.1f; // Tiempo entre cada frame en segundos
    int currentFrame = 0;
    int numFrames = 8; // Número total de frames en la animación
    int frameWidth = 250;
    int frameHeight = 270;

    while (window.isOpen())
    {
        // Procesar eventos
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Actualizar el frame de la animación
        if (clock.getElapsedTime().asSeconds() >= frameTime)
        {
            currentFrame = (currentFrame + 1) % numFrames;
            sprite.setTextureRect(sf::IntRect((currentFrame * 250)+45, 58, 250, 270));
            clock.restart();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}