#include <vector>
#include <algorithm>
#include "Board.h"
#include <iostream>

class Utils
{
public:
    static bool CheckValues(std::vector<char> list, char toCheck)
    {
        return std::ranges::all_of(list, [toCheck](char &c)
                                   { return c == toCheck; });
    }

    static bool ValidRow(const char c, int gridsize)
    {
        char x = std::toupper(c);

        if (x >= 'A' && x < 'A' + gridsize)
        {
            return true;
        }
        return false;
    }
    static bool ValidColumn(int col, int gridsize)
    {
        if (col < gridsize && col >= 0)
        {
            return true;
        }
        return false;
    }
};