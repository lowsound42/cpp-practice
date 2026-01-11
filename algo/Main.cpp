#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

struct Player
{
    std::string name;
    int health;
};

int main()
{
    std::vector<int> scores = {1, 42, 55, 2, 23};

    auto allAboveZero = std::ranges::all_of(scores, [](int &i)
                                            { return i > 0; });

    std::cout << allAboveZero << "\n";

    std::vector<std::string> names = {"gobi", "nash", "toby", "cosmo"};
    std::string userInput;
    std::cout << "Enter a name: ";
    std::cin >> userInput;

    auto it = std::ranges::find(names, userInput);

    if (it != names.end())
    {
        std::cout << "Found: " << *it << "\n";
    }
    else
    {
        std::cout << "it not here" << "\n";
    }

    std::vector<std::string> stuff = {"health", "mana", "Stamina", "charisma"};

    auto result = std::ranges::find_if(stuff, [](std::string &s)
                                       { return s.starts_with("S"); });

    if (result != names.end())
    {
        std::cout << "Found: " << *result << "\n";
    }
    else
    {
        std::cout << "it not here" << "\n";
    }
    std::vector<Player> players = {{"omar", 26}, {"geetha", 100}, {"gobi", 200}};

    auto unhealthy = std::ranges::count_if(players, [](const Player &p)
                                           { return p.health < 50; });

    if (unhealthy > 0)
    {
        std::cout << "Found: " << unhealthy << " unhealthy"
                                               "\n";
    }
    else
    {
        std::cout << "All good" << "\n";
    }

    return 0;
}