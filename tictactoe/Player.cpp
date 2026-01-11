#include "Player.h"
#include <iostream>
#include <string>

void Player::MakeMove(char row, int column, Board *board)
{
    board->MarkBox(int(row - 65), column, symbol_);
}

std::string Player::GetName()
{
    return name_;
}