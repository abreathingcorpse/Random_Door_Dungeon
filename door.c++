#ifndef SFML_H // SFML_H header guard
#define SFML_H

#include <SFML/Graphics.hpp>

#endif // SFML_H header guard

#include "door.h++"

// Default Constructor
Door::Door() : 
    mDoorDimensions(130.f,180.f),
    mDoorPosition(580.f,460.f)
    {
        setSize(sf::Vector2f(mDoorDimensions.x,mDoorDimensions.y));
        setFillColor(sf::Color::Red);
        setPosition(mDoorPosition.x,mDoorPosition.y);
    }

// Constructor Initializer List
Door::Door(sf::Vector2f DoorDimensions, sf::Vector2f DoorPosition) {
        mDoorDimensions = DoorDimensions;
        mDoorPosition = DoorPosition;
        setSize(sf::Vector2f(mDoorDimensions.x,mDoorDimensions.y));
        setFillColor(sf::Color::Red);
        setPosition(mDoorPosition.x,mDoorPosition.y);
}

Door::Door(sf::Vector2f DoorDimensions, sf::Vector2f DoorPosition, 
    sf::Color DoorColor) {
        mDoorDimensions = DoorDimensions;
        mDoorPosition = DoorPosition;
        mDoorColor = DoorColor;
        setSize(sf::Vector2f(mDoorDimensions.x,mDoorDimensions.y));
        setFillColor(mDoorColor);
        setPosition(mDoorPosition.x,mDoorPosition.y);
}

// Construct the 4 door types
//const Door Door::Red{mDoorDimensions, mDoorPosition, sf::Color::Red};