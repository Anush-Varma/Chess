//
// Created by anush on 02/10/2022.
//

#include "Knight.h"

Knight::Knight(char colour, int &x, int &y) {
    this->setIcon('K');
    this->setColour(colour);
    this->setXY(x,y);
}


bool Knight::move(int newRow, int newCol, char newColour, vector<vector<ChessPieces *>> &board) {
    if (this->colour == 'B' && newColour == 'W')
    {
        if ((newCol == this->getCol() +1) && (this->getRow() + 2 == newRow))
        {
            return true;
        }
        else if ((newCol == this->getCol() +2) && (this->getRow() + 1 == newRow))
        {
            return true;
        } else if ((newCol == this->getCol() + 2) && (this->getRow() - 1 == newRow))
        {
            return true;
        } else if ((newCol == this->getCol() +1) && (this->getRow() - 2 == newRow))
        {
            return true;
        } else if(((newCol == this->getCol() - 1) && (this->getRow() - 2 == newRow)))
        {
            return true;
        } else if ((newCol == this->getCol() - 2) && (this->getRow() - 1 == newRow))
        {
            return true;
        } else if ((newCol == this->getCol() - 2) && (this->getRow() + 1 == newRow))
        {
            return true;
        } else if((newCol == this->getCol() - 1) && (this->getRow() + 2 == newRow))
        {
            return true;
        }
    } else if (this->colour == 'W' && newColour == 'B')
    {

    } else if ((this->colour == 'B' && newColour == 'E') || (this->colour == 'W' && newColour == 'E'))
    {

    }


}