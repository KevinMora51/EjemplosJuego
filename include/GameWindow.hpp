class GameWindow {
public:
    GameWindow(int width, int height, const std::string& title) {
        window.create(sf::VideoMode(width, height), title);
    }

    bool isOpen() {
        return window.isOpen();
    }

    void close() {
        window.close();
    }

    void clear() {
        window.clear();
    }

    void display() {
        window.display();
    }

    // Cambia este método para aceptar cualquier sf::Drawable
    void draw(const sf::Drawable& drawable) {
        window.draw(drawable);
    }

    bool pollEvent(sf::Event& event) {
        return window.pollEvent(event);
    }

    sf::Vector2u getSize() {
        return window.getSize();
    }

private:
    sf::RenderWindow window;
};