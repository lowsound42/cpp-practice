#include "Player.h"
#include <iostream>
#include <string>

void Player::MakeMove(char row, int column, Board *board)
{
    board->MarkBox(int(row - 'A'), column, symbol_);
}

char Player::GetSymbol() const
{
    return symbol_;
}

std::string Player::GetName() const
{
    return name_;
}