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
    bool CheckRow(char symbolOne, char symbolTwo)
    {
        auto check = Utils::DoCheck(row_, symbolOne, symbolTwo);
        if(check) return true;
        return false;
    }
};