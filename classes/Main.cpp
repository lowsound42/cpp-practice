#include <iostream>
#include "Boss.h"
#include "Enemy.h"

int main()
{
    Boss boss = Boss("Bosser", 4, 10, 5);
    Enemy enemy = Enemy("Ener", 2, 6);

    enemy.Display();
    boss.Display();

    boss.SpecialAttack(enemy);

    enemy.Display();
    boss.Display();

    enemy.Attack(boss);
    enemy.Display();
    boss.Display();
}