#include <map>
#include <iostream>
#include <string>

void printScores(std::map<std::string, int> scores)
{
    for (const auto &[name, score] : scores)
    {
        std::cout << name << ": " << score << "\n";
    }
}

int main()
{
    std::map<std::string, int> scores{{"omar", 10}, {"geetha", 20}, {"gobi", 100}};
    printScores(scores);
    scores["gobi"] = 2000;
    printScores(scores);

    return 0;
}