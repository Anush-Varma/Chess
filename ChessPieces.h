//
// Created by anush on 01/09/2022.
//

#ifndef CHESS_2_0_CHESSPIECES_H
#define CHESS_2_0_CHESSPIECES_H
#include "vector"
using namespace std;

class ChessPieces{

public:
    char getIcon();
    int getCol();
    int getRow();
    virtual bool move(int newRow, int newCol, char newColour, vector<vector<ChessPieces*>> &board) = 0;
    void setIcon(char pieceIcon);
    void setColour(char colour);
    void setXY(int &x, int &y);
    char getColour();
    ChessPieces();


protected:
    char pieceIcon;
    char colour;
    int x;
    int y;
    void setX(int &x);
    void setY(int &y);

};


#endif //CHESS_2_0_CHESSPIECES_H
