#include "Board.h"
#include <iostream>
#include "Row.h"

void Board::DrawTopReference()
{
    std::cout << " ";
    for (int i = 0; i <= gridSize_; i++)
    {
        std::cout << " ";
        if (i < gridSize_)
        {
            std::cout << " " << i << " ";
        }
    }
    std::cout << "\n";
}

void Board::DrawFrame()
{
    std::cout << " ";
    for (int i = 0; i <= gridSize_; i++)
    {
        std::cout << "+";
        if (i < gridSize_)
        {
            std::cout << "---";
        }
    }
    std::cout << "\n";
}

void Board::DrawRow(int i)
{
    std::cout << char(i + 65);
    std::cout << "|";
    for (int j = 0; j < gridSize_; j++)
    {
        std::cout << " ";
        std::cout << rows_[i][j];
        std::cout << " ";
        std::cout << "|";
    }
    std::cout << "\n";
}

bool Board::ValidMove(int row, int column)
{
    return rows_[row][column] == ' ';
}

void Board::InitializeRows()
{
    for (int i = 0; i < gridSize_; i++)
    {
        rows_.emplace_back(Row(gridSize_));
    }
}

void Board::MarkBox(int row, int column, char symbol)
{
    if(rows_[row][column] != ' ')
    {
        std::cerr << "Box already marked!\n";
        return;
    }
    rows_[row][column] = symbol;
}

void Board::DrawGrid()
{
    DrawTopReference();
    for (int i = 0; i < gridSize_; i++)
    {
        DrawFrame();
        DrawRow(i);
    }
    DrawFrame();
}

bool Board::CheckRows(char symbol1, char symbol2)
{
    for (Row &row : rows_)
    {
        if (row.CheckRow(symbol1, symbol2))
        {
            return true;
        }
    }
    return false;
}
bool Board::CheckColumns(char symbol1, char symbol2)
{
    for (int i = 0; i < gridSize_; i++)
    {
        std::vector<char> temp;
        for (int j = 0; j < gridSize_; j++)
        {
            temp.emplace_back(rows_[j][i]);
        }

        auto check = Utils::DoCheck(temp, symbol1, symbol2);
        if(check) return true;
    }
    return false;
}

bool Board::CheckDiagonals(char symbol1, char symbol2)
{
    std::vector<char> mainDiag;
    for (int i = 0; i < gridSize_; i++)
    {
        mainDiag.emplace_back(rows_[i][i]);
    }

    auto checkMain = Utils::DoCheck(mainDiag, symbol1, symbol2);
        if(checkMain) return true;

    std::vector<char> antiDiag;
    for (int i = 0; i < gridSize_; i++)
    {
        antiDiag.emplace_back(rows_[i][gridSize_ - 1 - i]);
    }

    auto checkAnti = Utils::DoCheck(antiDiag, symbol1, symbol2);
        if(checkAnti) return true;

    return false;
}

int Board::GetGridSize()
{
    return gridSize_;
}

bool Board::CheckWin(char symbol1, char symbol2)
{
    return CheckColumns(symbol1, symbol2) || CheckDiagonals(symbol1, symbol2) || CheckRows(symbol1, symbol2);
}