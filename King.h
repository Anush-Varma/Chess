//
// Created by anush on 30/09/2022.
//

#ifndef CHESS_2_0_KING_H
#define CHESS_2_0_KING_H
#include "ChessPieces.h"

class King: public ChessPieces{
public:
    bool move(int newRow, int newCol, char newColour, vector<vector<ChessPieces*>> &board);
    King(char colour, int &x, int &y);
private:
    bool checkFreeSpaces(int &row, int &col, vector<vector<ChessPieces*>> &board);


};


#endif //CHESS_2_0_KING_H
