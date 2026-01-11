#include <memory>
#include "Weapon.h"
#include <vector>
#include "Sword.h"
#include "Bow.h"

int main() // main function
{
    std::vector<std::unique_ptr<Weapon>> weapons;

    weapons.emplace_back(std::make_unique<Sword>("Excalibur", 80));
    weapons.emplace_back(std::make_unique<Bow>("Eagle Eye", 45.5f));

    for (auto &weapon : weapons)
    {
        weapon->Display();
        weapon->Attack();
    }

    return 0;
}