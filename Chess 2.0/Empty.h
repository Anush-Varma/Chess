//
// Created by anush on 07/09/2022.
//

#ifndef CHESS_2_0_EMPTY_H
#define CHESS_2_0_EMPTY_H
#include "ChessPieces.h"

class Empty: ChessPieces{
public:
    Empty();
    bool move(int newRow, int newCol, char newColour) override;
};


#endif //CHESS_2_0_EMPTY_H
