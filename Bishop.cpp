//
// Created by anush on 16/09/2022.
//

#include "Bishop.h"
#include "cstdlib"

Bishop::Bishop(char Colour, int &x, int &y) {
    setIcon('B');
    setColour(Colour);
    setXY(x, y);
}

bool Bishop::move(int newRow, int newCol, char newColour, vector<vector<ChessPieces*>> &board) {
    if ((((this->getColour() == 'W') && (newColour == 'B')) || ((this->getColour() == 'B') && (newColour == 'W')))) // Check if new position is taking opposing players piece
    {
        int x = 0;
        if ((newCol > this->getCol()) && (newRow < this->getRow())) // moving NE
        {
            x = 1;
            return checkFreeSpaces(newRow, newCol, x, board);

        } else if ((newCol < this->getCol()) && (newRow < this->getRow())) // moving NW
        {
            x = 2;
            return checkFreeSpaces(newRow, newCol, x, board);

        } else if ((newCol > this->getCol()) && (newRow > this->getRow())) // moving SE
        {
            x = 3;
            return checkFreeSpaces(newRow, newCol, x, board);

        } else if ((newCol < this->getCol()) && (newRow > this->getRow())) // moving SW
        {
            x = 4;
            return checkFreeSpaces(newRow, newCol, x, board);
        }
    } else if (((this->getColour() == 'W') && (newColour == 'E')) || (this->getColour() == 'B') && (newColour == 'E')) // Check if new position for piece is moving to empty space
    {
        int x = 0;
        if ((newCol > this->getCol()) && (newRow < this->getRow())) // moving NE
        {
            x = 1;
            return checkFreeSpaces(newRow, newCol, x, board);

        } else if ((newCol < this->getCol()) && (newRow < this->getRow())) // moving NW
        {
            x = 2;
            return checkFreeSpaces(newRow, newCol, x, board);

        } else if ((newCol > this->getCol()) && (newRow > this->getRow())) // moving SE
        {
            x = 3;
            return checkFreeSpaces(newRow, newCol, x, board);

        } else if ((newCol < this->getCol()) && (newRow > this->getRow())) // moving SW
        {
            x = 4;
            return checkFreeSpaces(newRow, newCol, x, board);
        }
    } else
    {
        return false;
    }

}

bool Bishop::checkFreeSpaces(int &newRow, int &newCol, int &x ,vector<vector<ChessPieces *>> &board) {
    bool moveValid = true;
    switch (x) {

        case (1):
        {
            //move piece NE
            int row = this->getRow() - 1;
            int col = this->getCol() + 1;
            for (int i = 1; i < (abs(this->getRow() - newRow)); ++i) {
                if (board[col][row]->getIcon() == 'E')
                {
                    row--;
                    col++;
                } else
                {
                    moveValid = false;
                    row--;
                    col++;
                }
            }
        }
        case (2):
        {
            //move piece NW
            int row = this->getRow() - 1;
            int col = this->getCol() - 1;
            for (int i = 1; i < (abs(this->getCol() - newCol)); ++i) {
                if (board[col][row]->getIcon() == 'E') {
                    row--;
                    col--;
                } else
                {
                    moveValid = false;
                    row--;
                    col--;
                }
            }
        }
        case (3):
        {
            //move piece SE
            int row = this->getRow() + 1;
            int col = this->getCol() + 1;
            for (int i = 1; i < (abs(this->getCol() - newCol)); ++i) {
                if (board[col][row]->getIcon() == 'E') {
                    row++;
                    col++;
                } else
                {
                    moveValid = false;
                    row++;
                    col++;
                }
            }
        }
        case (4):
        {
            //move piece SW
            int row = this->getRow() + 1;
            int col = this->getCol() - 1;
            for (int i = 1; i < (abs(this->getCol() - newCol)); ++i) {
                if (board[col][row]->getIcon() == 'E') {
                    row++;
                    col--;
                } else
                {
                    moveValid = false;
                    row++;
                    col--;
                }
            }
        }
    }

    return moveValid;
}

