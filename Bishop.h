//
// Created by anush on 16/09/2022.
//

#ifndef CHESS_2_0_BISHOP_H
#define CHESS_2_0_BISHOP_H
#include "ChessPieces.h"
#include "vector"

class Bishop: public ChessPieces{
public:
    Bishop(char Colour, int &x, int &y);
    bool move(int newRow, int newCol, char newColour, vector<vector<ChessPieces*>> &board);
private:
    bool checkFreeSpaces(int &newRow, int &newCol, int &x ,vector<vector<ChessPieces*>> &board);
};


#endif //CHESS_2_0_BISHOP_H
