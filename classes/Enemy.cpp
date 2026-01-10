#include "Enemy.h"
#include <iostream>
#include <string>

Enemy::Enemy(std::string name, int lives, int damage)
{
    name_ = name;
    lives_ = lives;
    damage_ = damage;
}
void Enemy::Display() const
{
    std::cout << "Enemy: " << name_ << ", Lives: " << lives_ << ", Damage: " << damage_ << "\n";
};
void Enemy::Attack(Enemy &enemy)
{
    enemy.lives_ -= 1;
    std::cout << name_ << " attacks " << enemy.name_ << "!\n";
};