#include <SFML/Graphics.hpp>

int main () {
    sf::RenderWindow window(sf::VideoMode(640,480),
    "Random Door Dungeon");
    sf::RectangleShape door;
    door.setSize(sf::Vector2f(50,100));
    door.setFillColor(sf::Color::Red);
    door.setPosition(100,100);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(door);
        window.display();

    }
}