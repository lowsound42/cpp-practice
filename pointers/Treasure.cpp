#include <iostream>
#include <string>

struct Item
{
    std::string name;
};

class Chest
{
private:
    Item *item_ = nullptr;

public:
    void AddItem(Item *item)
    {
        item_ = item;
    }

    void RemoveItem()
    {
        item_ = nullptr;
    }

    void Display()
    {
        if (item_ != nullptr)
        {
            std::cout << item_->name << "\n";
        }
        else
        {
            std::cout << "The chest is empty" << "\n";
        }
    }
};

int main()
{
    Item sword{"sword"};
    Item shield{"shield"};

    Chest chest;

    chest.AddItem(&sword);
    chest.Display();

    chest.RemoveItem();

    chest.AddItem(&shield);
    chest.Display();
}