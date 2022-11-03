//
// Created by anush on 26/09/2022.
//

#ifndef CHESS_2_0_QUEEN_H
#define CHESS_2_0_QUEEN_H
#include "ChessPieces.h"

class Queen: public ChessPieces{
public:
    bool move(int newRow, int newCol, char newColour, vector<vector<ChessPieces*>> &board);
    Queen(char colour, int &x, int &y);
private:
    bool checkFreeSpaces(int &row, int &col, int x, vector<vector<ChessPieces*>> &board);

};


#endif //CHESS_2_0_QUEEN_H
