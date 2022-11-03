//
// Created by anush on 02/10/2022.
//

#ifndef CHESS_2_0_KNIGHT_H
#define CHESS_2_0_KNIGHT_H
#include "ChessPieces.h"

class Knight: public ChessPieces{
public:
public:
    bool move(int newRow, int newCol, char newColour, vector<vector<ChessPieces*>> &board);
    Knight(char colour, int &x, int &y);
private:
    bool checkFreeSpaces(int &row, int &col, int x, vector<vector<ChessPieces*>> &board);

};


#endif //CHESS_2_0_KNIGHT_H
