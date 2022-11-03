//
// Created by anush on 09/09/2022.
//

#include <iostream>
#include "Rook.h"

Rook::Rook(char colour, int &x, int &y) {
    this->setIcon('R');
    this->setColour(colour);
    this->setXY(x, y);
}
bool Rook::move(int newRow, int newCol, char newColour, vector<vector<ChessPieces*>> &board)
{
    if ((this->getRow() == newRow) && (newCol >= 0 && newCol <= 7) && (newColour == 'B') && (this->getColour() == 'W')){

        return checkFreeSpaces(newRow, newCol, board);

    } else if ((this->getRow() == newRow) && (newCol >= 0 && newCol <= 7) && (newColour == 'W') && (this->getColour() == 'B')){

        return checkFreeSpaces(newRow, newCol, board);

    } else if ((this->getCol() == newCol) && (newRow >= 0 && newRow <= 7) && (newColour == 'E')){

        return checkFreeSpaces(newRow, newCol, board);

    } else if ((this->getRow() == newRow) && (newCol >= 0 && newCol <= 7) && (newColour == 'E')){

        return checkFreeSpaces(newRow, newCol, board);

    } else if ((this->getCol() == newCol) && (newRow >= 0 && newRow <= 7) && (newColour == 'W') && (this->getColour() == 'B')) { // same column

        return checkFreeSpaces(newRow, newCol, board);

    } else if ((this->getCol() == newCol) && (newRow >= 0 && newRow <= 7) && (newColour == 'B') && (this->getColour() == 'W')) {

        return checkFreeSpaces(newRow, newCol, board);
    }
    else {
        return false;
    }
}

bool Rook::checkFreeSpaces(int &row, int &col, vector<vector<ChessPieces*>> &board) {
    bool moveValid = false;
    if (row < this->getRow()) // moving up
    {
        for (int i = this->getRow()-1; i >= row; --i) {
            if (board[col][i]->getIcon() == 'E')
            {
                moveValid = true;
            } else if (i == row)
            {
                moveValid = true;
            } else
            {
                moveValid = false;
            }
        }

    } else if (row > this->getRow()) // moving down
    {
        for (int i = this->getRow()+1; i <= row; ++i) {
            if (board[col][i]->getIcon() != 'E')
            {
                moveValid = true;
            } else if (i == row)
            {
                moveValid = true;
            } else
            {
                moveValid = false;
            }
        }

    } else if (col < this->getCol()) //moving left
    {
        for (int i = this->getCol()-1; i >= col; --i) {
            if (board[i][row]->getIcon() != 'E')
            {
                moveValid = true;
            } else if (i == col)
            {
                moveValid = true;
            } else
            {
                moveValid = false;
            }
        }

    } else if (col > this->getCol()) //moving right
    {
        for (int i = this->getCol()+1; i <= col; ++i) {
            if (board[i][row]->getIcon() != 'E')
            {
                moveValid = true;
            } else if (i == col)
            {
                moveValid = true;
            } else
            {
                moveValid = false;
            }
        }
    } else {
        std::cout << "Error in move" << endl;
        return false;
    }
    return moveValid;
}



