#pragma once
#include "Entity.h"
#include <string>
#include <iostream>

class Enemy : public Entity
{
public:
    Enemy(const std::string &name) : Entity(name) {};

    void Display()
    {
        std::cout << "Enemy version" << "\n";
    }

    void Update()
    {
        std::cout << "Enemy version" << "\n";
    }
};