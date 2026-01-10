#pragma once
#include "Enemy.h"

class Boss : public Enemy
{
private:
    int potions_;

public:
    Boss(std::string name, int lives, int damage, int potions);
    void SpecialAttack(Enemy &enemy);
    void Display() const;
};