#ifndef DOOR_H // DOOR_H header guard
#define DOOR_H

#ifndef SFML_H // SFML_H header guard
#define SFML_H

#include <SFML/Graphics.hpp>

#endif // SFML_H header guard

class Door : public sf::RectangleShape {

    public:
        Door(); // Default Constructor
        Door(sf::Vector2f DoorDimensions, sf::Vector2f DoorPosition,
            sf::Color DoorColor);
        sf::Vector2f mDoorDimensions;
        sf::Vector2f mDoorPosition;
        sf::Color mDoorColor;

    private:
};

#endif // DOOR_G header guard