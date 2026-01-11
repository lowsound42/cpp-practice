#pragma once
#include "Weapon.h"
#include <string>
#include <iostream>

class Sword : public Weapon
{
private:
    int sharpness_;

public:
    Sword(std::string name, int sharpness) : Weapon(name), sharpness_(sharpness) {};

    void Attack()
    {
        std::cout << "Swinging the sword!\n";
    }

    void Display()
    {
        std::cout << "Sword: " << name_ << ", Sharpness: " << sharpness_ << "\n";
    }
};