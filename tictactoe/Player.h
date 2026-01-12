#pragma once
#include "Board.h"
#include <string>

class Player
{
private:
    char symbol_;
    std::string name_;

public:
    Player(char symbol, std::string name) : symbol_(symbol), name_(name) {};
    void MakeMove(char row, int column, Board *board);
    std::string GetName() const;
    char GetSymbol() const;
};