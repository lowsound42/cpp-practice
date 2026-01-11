#include <string>
#include <iostream>

int main()
{
    struct Resource
    {
        std::string name;
        int quantity;
    };

    Resource resource1 = Resource({"bicycles", 5});
    Resource resource2 = Resource(Resource{"roller blades", 12});

    Resource *selected = nullptr;
    selected = &resource1;
    std::cout << selected->name << ": " << selected->quantity << "\n";
    selected = &resource2;
    std::cout << selected->name << ": " << selected->quantity << "\n";
    selected = nullptr;

    if (selected == nullptr)
    {
        std::cout << "No resource currently selected\n";
    }

    return 0;
}