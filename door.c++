#ifndef SFML_H // SFML_H header guard
#define SFML_H

#include <SFML/Graphics.hpp>

#endif // SFML_H header guard

#include <iostream>
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

void Door::loadClubSprite() {
    if (!mClubTexture.loadFromFile(mClubTexturePath)) {
        std::cerr << "Could not load the Club Texture" << std::endl;
    }
    mWeaponSprite.setTexture(mClubTexture);
    mWeaponSprite.setScale(4.f,4.f);
    std::cout << "Texture loaded successfully" << std::endl;
}

//void Door::draw(sf::RenderTarget& target, sf::RenderStates states = sf::RenderStates::Default) const {
//    target.draw(mWeaponSprite);
//}