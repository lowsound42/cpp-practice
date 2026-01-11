#include <unordered_map>
#include <iostream>
#include <string>

int main()
{
    std::unordered_map<std::string, int> locales = {{"mordor", 4200},
                                                    {"pelenor fields", 60000},
                                                    {"death star", 20000000}};

    std::string userInput;
    std::cout << "What's the place you want to check?" << "\n";
    std::cin >> userInput;

    std::cout << locales[userInput];

    return 0;
}