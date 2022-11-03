//
// Created by anush on 07/09/2022.
//

#include "Empty.h"

Empty::Empty(int &x, int &y) {
    setIcon('E');
    setXY(x,y);
    setColour('E');
}

Empty::Empty() {
    setIcon('E');
    setColour('E');
}

bool Empty::move(int newRow, int newCol, char newColour, vector<vector<ChessPieces*>> &board) {
    return false;
}