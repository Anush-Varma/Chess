//
// Created by anush on 25/08/2022.
//

#ifndef CHESS_2_0_BOARD_H
#define CHESS_2_0_BOARD_H

#include <memory>
#include "vector"
#include "iostream"
using namespace std;
#include "ChessPieces.h"

class Board {
public:
    Board();
    vector<vector<shared_ptr<ChessPieces>>> board;
    ~Board();


};


#endif //CHESS_2_0_BOARD_H
