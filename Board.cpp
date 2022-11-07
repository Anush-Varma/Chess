//
// Created by anush on 25/08/2022.
//

#include "Board.h"
#include "Empty.h"
#include "Rook.h"
#include "Pawn.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"
#include "Knight.h"

Board::Board() {
    for (int col = 0; col < boardSize; col++) {
        vector<ChessPieces*> v;
        for (int row = 0; row < boardSize; row++)
            v.push_back((ChessPieces*)(new Empty(row, col)));
        board.push_back(v);
    }
    setupBoard();
}

Board::~Board() {
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            delete board[i][j];
}

void Board::outputBoard() {
    cout << "        A      B      C      D      E      F      G      H" << endl;
    int x = 8;
    for (int i = 0; i < boardSize; ++i) {

        for (int j = 0; j < boardSize; ++j) {
            if (j == 0)
            {
                std::cout << "| " << x-- << " |" << "| " << board[j][i]->getColour() << " " << board[j][i]->getIcon() << " |";
            } else {
                std::cout << "| " << board[j][i]->getColour() << " " << board[j][i]->getIcon() << " |";
            }
        }
        std::cout << endl;
    }
}

void Board::setupBoard()
{
    for (int col = 0; col < boardSize; ++col) {
        for (int row = 0; row < 8; ++row) {
            //set white pieces in correct position
            if (((col==0) && (row == 0)) || ((col == 7) && (row == 0)))//black rook
            {
                board[col][row] = (ChessPieces*)(new Rook('B', col, row));
            }
            else if (row == 1)//black pawn
            {
                board[col][row] = (ChessPieces*)(new Pawn('B', col, row));
            }
            else if (((col==0) && (row == 7)) || ((col == 7) && (row == 7))) // white rook
            {
                board[col][row] = (ChessPieces*)(new Rook('W', col, row));
            }
            else if (row == 6)//white pawn
            {
                board[col][row] = (ChessPieces*)(new Pawn('W', col, row));

            } else if ((row == 7) && ((col == 2) || (col == 5))) // white bishop
            {
                board[col][row] = (ChessPieces*)(new Bishop('W', col, row));

            } else if ((row == 0) && ((col == 2) || (col == 5))) // black bishop
            {
                board[col][row] = (ChessPieces*)(new Bishop('B', col, row));

            } else if ((row == 7) && (col == 3)) // White Queen
            {
                board[col][row] = (ChessPieces*)(new Queen('W', col, row));

            } else if((row == 0) && (col == 3))// Black Queen
            {
                board[col][row] = (ChessPieces*)(new Queen('B', col, row));

            } else if ((row == 7) && (col == 4)) // White King
            {
                board[col][row] = (ChessPieces*)(new King('W', col, row));

            } else if((row == 0) && (col == 4)) // Black King
            {
                board[col][row] = (ChessPieces*)(new King('B', col, row));

            } else if ((row == 0) && ((col == 1) || (col == 6)))
            {
                board[col][row] = (ChessPieces*)(new Knight('B', col, row));

            } else if ((row == 7) && (col == 1 || col == 6))
            {
                board[col][row] = (ChessPieces*)(new Knight('W', col, row));
            }

        }
    }
}


int Board::getPieceColPos(char icon, char colour) {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if (board[i][j]->getIcon() == icon && board[i][j]->getColour() == colour)
            {
                return board[i][j]->getCol();
            }
        }
    }
}

int Board::getPieceRowPos(char icon, char colour) {
    for (int i = 0; i < boardSize; ++i) {
        for (int j = 0; j < boardSize; ++j) {
            if (board[i][j]->getIcon() == icon && board[i][j]->getColour() == colour)
            {
                return board[i][j]->getRow();
            }
        }
    }
}
