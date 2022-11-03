//
// Created by anush on 15/09/2022.
//

#include "Pawn.h"


Pawn::Pawn(char colour, int &x, int &y) {
    setIcon('P');
    setColour(colour);
    setXY(x, y);
}


bool Pawn::move(int newRow, int newCol, char newColour, vector<vector<ChessPieces*>> &board) {

    if ((this->colour == 'W') && (newRow == this->getRow() - 1) && (this->getCol() == newCol)) {
        return true;
        //Move white pawn up one
    } else if ((this->colour == 'B') && (newRow == this->getRow() + 1) && (this->getCol() == newCol)) {
        return true;
        //Move black pawn up one
    } else if ((this->colour == 'B') && (newRow == this->getRow() + 2) && (this->getCol() == newCol) && (!firstMove)) {
        return true;
        //Move black pawn up 2 from starting position
    } else if ((this->colour == 'W') && (newRow == this->getRow() - 2) && (this->getCol() == newCol) && (!firstMove)) {
        return true;
        //Move white pawn up 2 from starting position
    } else if ((this->colour == 'W') && (newRow == this->getRow() - 1) &&
               ((this->getCol() + 1 == newCol) || (this->getCol() - 1 == newCol)) && (newColour == 'B')) {
        return true;
        //Move white pawn diagonally if another piece is on the diagonal space
    } else if ((this->colour == 'B') && (newRow == this->getRow() + 1) &&
               ((this->getCol() + 1 == newCol) || (this->getCol() - 1 == newCol)) && (newColour == 'W')) {
        return true;
        //Move black pawn diagonally if another piece is on the diagonal space
    } else {
        return false;
        // return false is move is invalid
    }
}