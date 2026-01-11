#include <vector>
#include "Player.h"
#include "Enemy.h"
#include "Entity.h"
#include <memory>

int main()
{
    std::vector<std::unique_ptr<Entity>> entities;

    entities.emplace_back(std::make_unique<Player>("Omar"));
    entities.emplace_back(std::make_unique<Enemy>("Ali"));

    for (auto &entity : entities)
    {
        entity->Display();
        entity->Update();
    }
    return 0;
}