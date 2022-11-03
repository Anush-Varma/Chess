//
// Created by anush on 07/09/2022.
//

#ifndef CHESS_2_0_EMPTY_H
#define CHESS_2_0_EMPTY_H
#include "ChessPieces.h"
#include "vector"
using namespace std;

class Empty: ChessPieces{
public:
    Empty(int &x, int &y);
    Empty();
    bool move(int newRow, int newCol, char newColour, vector<vector<ChessPieces*>> &board);
};


#endif //CHESS_2_0_EMPTY_H
