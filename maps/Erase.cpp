#include <iostream>
#include <unordered_map>
#include <string>

int main()
{
    std::unordered_map<unsigned, std::string> players =
        {
            {101, "Mario"},
            {102, "Luigi"},
            {103, "Peach"}};

    unsigned id;
    std::cout << "Enter player ID to remove: ";
    std::cin >> id;

    players.erase(id);

    std::cout << "Remaining players:\n";
    for (const auto &[key, name] : players)
    {
        std::cout << key << ": " << name << '\n';
    }
}