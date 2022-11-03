//
// Created by anush on 25/08/2022.
//

#include "Board.h"
Board::Board() {
    board = vector<vector<shared_ptr<ChessPieces>>>(8, vector<shared_ptr<ChessPieces>>(8));
}

Board::~Board() {
    cout << "Destroyed" << endl;
}
