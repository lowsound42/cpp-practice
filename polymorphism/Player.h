#pragma once
#include "Entity.h"
#include <string>
#include <iostream>

class Player : public Entity
{
public:
    Player(const std::string &name) : Entity(name) {};

    void Update()
    {
        std::cout << "Player version" << "\n";
    }

    void Display()
    {
        std::cout << "Player version" << "\n";
    }
};