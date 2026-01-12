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
    bool CheckWin();
    bool CheckRows();
    bool CheckColumns();
    bool CheckDiagonals();
    int GetGridSize();
    bool ValidMove(int row, int column);
};
