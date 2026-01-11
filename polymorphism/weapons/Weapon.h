#pragma once
#include <string>

class Weapon
{
protected:
    std::string name_;

public:
    Weapon(std::string name) : name_(name) {};
    virtual ~Weapon() = default;
    virtual void Attack() = 0;
    virtual void Display() = 0;
};