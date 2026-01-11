#pragma once
#include <vector>
#include <string>
#include <algorithm>
#include "Utils.h"

class Row
{
private:
    std::vector<char> row_;
    Utils utils_;

public:
    Row(int size) : row_(size, ' ') {};
    char &operator[](int x) { return row_[x]; }
    const char &operator[](int x) const { return row_[x]; }
    bool CheckRow()
    {
        auto checkX = Utils::CheckValues(row_, 'X');
        auto checkO = Utils::CheckValues(row_, '0');
        if (checkX || checkO)
        {
            return true;
        }
        return false;
    }
};