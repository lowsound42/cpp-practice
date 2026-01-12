#include <iostream>
#include "Board.h"
#include "Player.h"

void gameLoop(Board *board, Player &player, bool &playerOneTurn, int &moveCount, int &maxMoves)
{
    char row;
    int column;
    std::cout << player.GetName() << ", enter a slot (row <space> column, e.g. A 1): ";
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
    player.MakeMove(std::toupper(row), column, board);
    moveCount++;
    playerOneTurn = !playerOneTurn;
    board->DrawGrid();
}

int main()
{
    int gridSize;
    std::cout << "Enter a grid size: ";
    std::cin >> gridSize;
    int moveCount = 0;
    int maxMoves = gridSize * gridSize;

    Player playerOne = Player('X', "Player 1");
    Player playerTwo = Player('O', "Player 2");

    Board board = Board(gridSize);
    board.InitializeRows();
    board.DrawGrid();

    bool isGameOver = false;
    bool playerOneTurn = true;

    while (!isGameOver)
    {
  
        Player *player = nullptr;
        if (playerOneTurn)
        {
            player = &playerOne;
        }
        else
        {
            player = &playerTwo;
        }
        gameLoop(&board, *player, playerOneTurn, moveCount, maxMoves);
        if (moveCount >= maxMoves) {
            std::cout << "It's a draw!\n";
            break;;
        }
        isGameOver = board.CheckWin(playerOne.GetSymbol(), playerTwo.GetSymbol());
    }

    return 0;
}