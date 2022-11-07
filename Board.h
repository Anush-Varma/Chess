//
// Created by anush on 25/08/2022.
//

#ifndef CHESS_2_0_BOARD_H
#define CHESS_2_0_BOARD_H

#include <memory>
#include "vector"
#include "iostream"
#include "ChessPieces.h"

class Board {

public:
    std::vector<std::vector<ChessPieces*>> board;
    Board();
    ~Board();
    void outputBoard();

private:
    void setupBoard();
};


#endif //CHESS_2_0_BOARD_H