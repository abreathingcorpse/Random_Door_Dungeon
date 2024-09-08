#ifndef DOOR_H // DOOR_H header guard
#define DOOR_H

#ifndef SFML_H // SFML_H header guard
#define SFML_H

#include <SFML/Graphics.hpp>

#endif // SFML_H header guard

class Door : public sf::RectangleShape {

    public:
        Door(); // Default Constructor
        // Other Constructors
        Door(sf::Vector2f DoorDimensions, sf::Vector2f DoorPosition);
        Door(sf::Vector2f DoorDimensions, sf::Vector2f DoorPosition,
            sf::Color DoorColor);

        sf::Vector2f mDoorDimensions;
        sf::Vector2f mDoorPosition;
        sf::Color mDoorColor;

        // Define the 4 door types
//        static const Door Red;
//        static const Door Green;
//        static const Door Blue;
//        static const Door Gray;
        std::vector<sf::Color> available_door_colors = {sf::Color::Red,
                                                        sf::Color::Green,
                                                        sf::Color::Blue,
                                                        sf::Color::White};

    private:
};

#endif // DOOR_G header guard