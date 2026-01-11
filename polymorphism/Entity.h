#pragma once
#include <iostream>
#include <string>

class Entity
{
protected:
    std::string name_;

public:
    Entity(const std::string &name) : name_(name) {};
    virtual ~Entity() = default;

    virtual void Update() = 0;

    virtual void Display() = 0;
};