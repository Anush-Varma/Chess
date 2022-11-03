//
// Created by anush on 15/09/2022.
//

#ifndef CHESS_2_0_PAWN_H
#define CHESS_2_0_PAWN_H
#include "ChessPieces.h"
#include "Board.h"

class Pawn: public ChessPieces{
    bool firstMove = false;
public:
    Pawn(char colour, int &x, int &y);
    bool move(int newRow, int newCol, char newColour, vector<vector<ChessPieces*>> &board);
};


#endif //CHESS_2_0_PAWN_H
