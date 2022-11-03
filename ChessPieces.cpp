//
// Created by anush on 01/09/2022.
//

#include "ChessPieces.h"


ChessPieces::ChessPieces()
{

}

char ChessPieces::getIcon()
{
    return pieceIcon;
}

char ChessPieces::getColour() {
    return colour;
}

int ChessPieces::getCol() {
    return x;
}

int ChessPieces::getRow() {
    return y;
}

void ChessPieces::setX(int &newX) {
    this->x = newX;
}

void ChessPieces::setY(int&newY) {
    y = newY;
}

void ChessPieces::setXY(int &x, int &y){
    setX(x);
    setY(y);
}


void ChessPieces::setIcon(char newIcon){
    pieceIcon = newIcon;
}

void ChessPieces::setColour(char newColour) {
    colour = newColour;
}




