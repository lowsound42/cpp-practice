#include <iostream>
#include "Board.h"
#include "Player.h"

void gameLoop(char row, int column, Board *board, Player *player, bool *playerOneTurn)
{
    std::cout << player->GetName() << ", enter a slot (row <space> column, e.g. A 1): ";
    std::cin >> row >> column;
    if (!Utils::ValidRow(row, board->GetGridSize()))
    {
        std::cerr << "Invalid row! Please try again.\n";
        return;
    }
    if (!Utils::ValidColumn(column, board->GetGridSize()))
    {
        std::cerr << "Invalid column! Please try again.\n";
        return;
    }
    if(!board->ValidMove(std::toupper(row) - 'A', column))
    {
        std::cerr << "Slot already taken! Please try again.\n";
        return;
    }
    player->MakeMove(std::toupper(row), column, board);
    *playerOneTurn = !(*playerOneTurn);

    board->DrawGrid();
}

int main()
{
    int gridSize;
    std::cout << "Enter a grid size: ";
    std::cin >> gridSize;

    Player playerOne = Player('X', "Player 1");
    Player playerTwo = Player('0', "Player 2");

    Board board = Board(gridSize);
    board.InitializeRows();
    board.DrawGrid();

    bool isGameOver = false;
    bool playerOneTurn = true;
    bool *turn = &playerOneTurn;

    while (!isGameOver)
    {
        char row;
        int column;
        Player *player = nullptr;
        if (playerOneTurn)
        {
            player = &playerOne;
        }
        else
        {
            player = &playerTwo;
        }
        gameLoop(std::toupper(row) - 'A', column, &board, player, turn);
        isGameOver = board.CheckWin();
    }

    return 0;
}