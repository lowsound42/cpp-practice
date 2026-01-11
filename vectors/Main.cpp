#include <vector>
#include <iostream>

int main()
{
    std::vector<int> playerScores;
    bool youDone = false;
    while (!youDone)
    {
        int input;
        char more;
        std::cout << "Enter a number: ";
        std::cin >> input;

        playerScores.emplace_back(input);
        std::cout << "Do you want to do more? y/n";
        std::cin >> more;

        if (more == 'n')
        {
            youDone = true;
        }
    }

    for (const int &number : playerScores)
    {
        std::cout << number << "\n";
    }

    std::vector<std::string> enemies1 = {"Slime", "Orc", "Goblin"};

    enemies1.emplace(enemies1.begin(), "Dragon");

    std::cout << "Enemies on screen:\n";
    for (const std::string &enemy : enemies1)
    {
        std::cout << enemy << '\n';
    }

    std::vector<int> numbers = {10, 20, 30, 40, 50};

    std::size_t index;
    std::cout << "Enter index to remove: ";
    std::cin >> index;

    if (index >= 0 && index < numbers.size())
    {
        numbers.erase(numbers.begin() + index);
    }

    std::cout << "Updated list:\n";
    for (int n : numbers)
    {
        std::cout << n << '\n';
    }

    std::vector<std::string> enemies = {"Slime", "Bat", "Orc", "Slime"};

    std::string name;
    std::cout << "Remove all enemies named: ";
    std::cin >> name;

    std::erase(enemies, name);

    std::cout << "Remaining enemies:\n";
    for (const std::string &e : enemies)
    {
        std::cout << e << '\n';
    }
    return 0;
}