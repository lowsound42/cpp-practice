#pragma once

#include <string>

class Enemy
{
protected:
    std::string name_;
    int lives_;
    int damage_;

public:
    Enemy(std::string name, int lives, int damage);
    void Display() const;
    void Attack(Enemy &enemy);
};