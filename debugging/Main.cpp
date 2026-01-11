#include <iostream>
#include <array>

int SumPositive(std::array<int, 5> values)
{
    int total = 0;

    for (int i = 0; i <= values.size() - 1; i++)
    {
        if (values[i] > 0)
        {
            total += values[i];
        }
    }

    return total;
}

int main()
{
    std::array<int, 5> data = {3, -2, 7, -5, 4};

    int result = SumPositive(data);

    std::cout << "Result = " << result << '\n';
}