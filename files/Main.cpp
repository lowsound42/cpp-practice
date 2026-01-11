#include <fstream>
#include <string>
#include <iostream>
#include <vector>

struct Player
{
    std::string name;
    int score;
};

int main()
{
    int score;
    std::string name;

    std::cout << "Enter a name: ";
    std::cin >> name;

    std::cout << "Enter a score: ";
    std::cin >> score;

    std::ofstream file("Scores.txt");
    file << name << " " << score;
    file.close();

    std::ifstream file2("Scores.txt");
    if (!file2)
    {
        std::cout << "Not here!" << "\n";
        return 1;
    }

    std::string line;
    int count = 0;

    while (std::getline(file2, line))
    {
        std::cout << line << "\n";
        count++;
    }

    std::cout << "total scores loaded: " << count << "\n";
    file2.close();

    std::vector<Player> players;
    std::string name2;
    int score2;

    std::ifstream file3("Scores.txt");
    if (!file3)
    {
        std::cout << "Not here!" << "\n";
        return 1;
    }

    while (file3 >> name2 >> score2)
    {
        players.emplace_back(name2, score2);
    }
    file3.close();

    const int bonus = 10;
    for (Player &player : players)
    {
        player.score += bonus;
    }

    std::ofstream output("Scores.txt");
    if (!output)
    {
        std::cout << "Failed to open Scores.txt for writing.\n";
        return 1;
    }

    for (const Player &player : players)
    {
        output << player.name << ' ' << player.score << '\n';
    }
    output.close();
    return 0;
}