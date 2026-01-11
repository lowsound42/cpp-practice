#include <iostream>
#include <string>
#include <vector>

class Fighter
{
private:
    std::string name_;
    int power_;

public:
    Fighter(const std::string &name, int power)
        : name_(name), power_(power)
    {
    }

    const std::string &GetName() const
    {
        return name_;
    }

    void Display() const
    {
        std::cout << name_ << " (Power: " << power_ << ")\n";
    }
};

class Arena
{
private:
    std::vector<Fighter> fighters_;

public:
    void AddFighter(const Fighter &fighter)
    {
        fighters_.push_back(fighter);
    }

    Fighter *FindFighter(const std::string &name)
    {
        for (auto &fighter : fighters_)
        {
            if (fighter.GetName() == name)
            {
                return &fighter;
            }
        }
        return nullptr;
    }
};

int main()
{
    Arena arena;

    arena.AddFighter(Fighter("Arthur", 85));
    arena.AddFighter(Fighter("Lancelot", 90));
    arena.AddFighter(Fighter("Galahad", 75));

    Fighter *found = arena.FindFighter("Lancelot");

    if (found)
    {
        found->Display();
    }
    else
    {
        std::cout << "No fighter found.\n";
    }

    found = arena.FindFighter("Merlin");

    if (found)
    {
        found->Display();
    }
    else
    {
        std::cout << "No fighter found.\n";
    }
}