#pragma once
#include "Weapon.h"
#include <string>
#include <iostream>

class Bow : public Weapon
{
private:
    float range_;

public:
    Bow(std::string name, float range) : Weapon(name), range_(range) {};

    void Attack()
    {
        std::cout << "Shooting an arrow!\n";
    }

    void Display()
    {
        std::cout << "Sword: " << name_ << ", Range: " << range_ << "\n";
    }
};