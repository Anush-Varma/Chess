//
// Created by anush on 01/09/2022.
//

#ifndef CHESS_2_0_CHESSPIECES_H
#define CHESS_2_0_CHESSPIECES_H


class ChessPieces{

public:
    virtual bool move(int newRow, int newCol, char newColour) = 0;
    char getIcon();
    int getCol();
    int getRow();

    void setIcon(char pieceIcon);
    void setColour(char colour);
    void setXY(int x, int y);
    char getColour();
    ChessPieces();


protected:
    char pieceIcon;
    char colour;
    int x;
    int y;
    void setX(int x);
    void setY(int y);

};


#endif //CHESS_2_0_CHESSPIECES_H
