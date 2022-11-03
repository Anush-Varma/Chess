//
// Created by anush on 26/09/2022.
//

#include <iostream>
#include "Queen.h"


/**
 * Queen class
 * Handles and processes movement off Queen chess piece
 * @param colour
 * @param x
 * @param y
 */


Queen::Queen(char colour, int &x, int &y) {
    {
        this->setIcon('Q');
        this->colour = colour;
        this->setXY(x,y);
    }
}

bool Queen::move(int newRow, int newCol, char newColour, vector<vector<ChessPieces *>> &board) {
    {
        if ((this->getRow() == newRow) && (newCol >= 0 && newCol <= 7) && (newColour == 'B') &&
            (this->getColour() == 'W')) {

            return checkFreeSpaces(newRow, newCol, 0, board);

        } else if ((this->getRow() == newRow) && (newCol >= 0 && newCol <= 7) && (newColour == 'W') &&
                   (this->getColour() == 'B')) {

            return checkFreeSpaces(newRow, newCol, 0, board);

        } else if ((this->getCol() == newCol) && (newRow >= 0 && newRow <= 7) && (newColour == 'E')) {

            return checkFreeSpaces(newRow, newCol, 0, board);

        } else if ((this->getRow() == newRow) && (newCol >= 0 && newCol <= 7) && (newColour == 'E')) {

            return checkFreeSpaces(newRow, newCol, 0, board);

        } else if ((this->getCol() == newCol) && (newRow >= 0 && newRow <= 7) && (newColour == 'W') &&
                   (this->getColour() == 'B')) { // same column

            return checkFreeSpaces(newRow, newCol, 0, board);

        } else if ((this->getCol() == newCol) && (newRow >= 0 && newRow <= 7) && (newColour == 'B') &&
                   (this->getColour() == 'W')) {

            return checkFreeSpaces(newRow, newCol, 0, board);
        }
        if ((((this->getColour() == 'W') && (newColour == 'B')) || ((this->getColour() == 'B') && (newColour ==
                                                                                                   'W')))) // Check if new position is taking opposing players piece
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
        } else if (((this->getColour() == 'W') && (newColour == 'E')) || (this->getColour() == 'B') && (newColour ==
                                                                                                        'E')) // Check if new position for piece is moving to empty space
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
            } else {
                return false;
            }
        }
    }
}

bool Queen::checkFreeSpaces(int &newRow, int &newCol, int x, vector<vector<ChessPieces *>> &board) {
    bool moveValid = false;
    if (newRow < this->getRow()) // moving up
    {
        for (int i = this->getRow()-1; i >= newRow; --i) {
            if (board[newCol][i]->getIcon() == 'E')
            {
                moveValid = true;
            } else if (i == newRow)
            {
                moveValid = true;
            } else
            {
                moveValid = false;
            }
        }

    } else if (newRow > this->getRow()) // moving down
    {
        for (int i = this->getRow()+1; i <= newRow; ++i) {
            if (board[newCol][i]->getIcon() != 'E')
            {
                moveValid = true;
            } else if (i == newRow)
            {
                moveValid = true;
            } else
            {
                moveValid = false;
            }
        }

    } else if (newCol < this->getCol()) //moving left
    {
        for (int i = this->getCol()-1; i >= newCol; --i) {
            if (board[i][newRow]->getIcon() != 'E')
            {
                moveValid = true;
            } else if (i == newCol)
            {
                moveValid = true;
            } else
            {
                moveValid = false;
            }
        }

    } else if (newCol > this->getCol()) //moving right
    {
        for (int i = this->getCol()+1; i <= newCol; ++i) {
            if (board[i][newRow]->getIcon() != 'E')
            {
                moveValid = true;
            } else if (i == newCol)
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