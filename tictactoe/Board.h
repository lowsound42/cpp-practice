#pragma once
#include <vector>
#include <string>
#include "Row.h"

class Board
{
private:
    int gridSize_;
    std::vector<Row> rows_;

public:
    Board(int gridSize) : gridSize_(gridSize) {

                          };
    void InitializeRows();
    void DrawFrame();
    void DrawRow(int rowNum);
    void DrawGrid();
    void DrawTopReference();
    void DrawSideReference();
    void MarkBox(int row, int column, char symbol);
    bool CheckWin(char symbolOne, char symbolTwo);
    bool CheckRows(char symbol1, char symbol2);
    bool CheckColumns(char symbol1, char symbol2);
    bool CheckDiagonals(char symbol1, char symbol2);
    int GetGridSize();
    bool ValidMove(int row, int column);
};
