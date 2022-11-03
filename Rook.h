//
// Created by anush on 09/09/2022.
//

#ifndef CHESS_2_0_ROOK_H
#define CHESS_2_0_ROOK_H
#include "ChessPieces.h"
#include "vector"

using namespace std;

class Rook: public ChessPieces{
public:
    bool move(int newRow, int newCol, char newColour, vector<vector<ChessPieces*>> &board);
    Rook(char colour, int &x, int &y);
private:
    bool checkFreeSpaces(int &row, int &col, vector<vector<ChessPieces*>> &board);

};


#endif //CHESS_2_0_ROOK_H
