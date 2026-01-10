#include "Boss.h"
#include <iostream>
#include <string>

Boss::Boss(std::string name, int lives, int damage, int potions)
    : Enemy(name, lives, damage)
{
    potions_ = potions;
}
void Boss::Display() const
{
    Enemy::Display();
    std::cout << "Potions: " << potions_ << "\n";
};
void Boss::SpecialAttack(Enemy &enemy)
{
    if (potions_ > 0)
    {
        Enemy::Attack(enemy);
        potions_ = potions_ - 1;
        std::cout << "The enemy is immobilized!\n";
    }
    else
    {
        std::cout << name_ << " has no potions left!\n";
    }
};