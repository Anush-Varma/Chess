//
// Created by anush on 30/09/2022.
//

#include "King.h"
#include "cstdlib"

King::King(char colour, int &x, int &y) {
    this->setIcon('K');
    this->colour = colour;
    this->setXY(x, y);
}

bool King::move(int newRow, int newCol, char newColour, vector<vector<ChessPieces *>> &board) {
    {
        if ((this->getColour() == 'B') && (newColour == 'W') && (abs(this->getCol() - newCol) == 1))
        {
            return true;
        } else if ((this->getColour() == 'B') && (newColour == 'E') && (abs(this->getCol() - newCol) == 1))
        {
            return true;
        } else if ((this->getColour() == 'W') && (newColour == 'B') && (abs(this->getCol() - newCol) == 1))
        {
            return true;
        } else if ((this->getColour() == 'W') && (newColour == 'E') && (abs(this->getCol() - newCol) == 1))
        {
            return true;
        }
    }
}
