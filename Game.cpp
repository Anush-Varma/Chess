//
// Created by anush on 07/09/2022.
//

#include <iostream>
#include "Game.h"
#include "Board.h"
#include "Empty.h"
#include "Player.h"

Game::Game() {
    Board board;
    Player p1;
    Player p2;
    gameStart(board, p1, p2);
}

void Game::gameStart(Board &board, Player p1, Player p2) {
    std::cout << "Welcome to Chess Game" << std::endl;
    bool correctInput = true;

    while (correctInput){
        std::cout << "Enter 1 to continue or 2 to exit:";
        try {
            int x;
            std::cin >> x;
            if (x == 1) {
                correctInput = false;
            } else if (x == 2){
                exit(0);
            } else{
                correctInput = true;
            }
        } catch (std::exception &e) {
            std::cout << "Invalid Input, Enter either 1 or 2";
        }
    }
    correctInput = true;
    std::cout << std::endl;
    checkMove(board, p1);
    endGameCheck(board, p1, 'W');
    checkMove(board, p2);
    endGameCheck(board, p2, 'B');

}

void Game::endGameCheck(Board &board, Player p, char colour) {
    int kingXPos = board.getPieceColPos('K', colour);
    int kingYPos = board.getPieceRowPos('K', colour);
    for (int i = kingYPos; i < board.boardSize; ++i) {
        for (int j = kingXPos; j < board.boardSize; ++j) {

        }
    }

}


void Game::checkMove(Board &board, Player p) {
    bool moveValid = true;
    while(moveValid) {
        board.outputBoard();
        p.startTurn();
        if (board.board[p.convertCoords(p.currentPos()[0])][p.convertCoords(p.currentPos()[1])]->move(
                p.convertCoords(p.newPos()[1]), p.convertCoords(p.newPos()[0]),
                board.board[p.convertCoords(p.newPos()[1])][p.convertCoords(p.newPos()[0])]->getColour(),
                board.board)) //Checks if player p move is valid
        {

            board.board[p.convertCoords(p.newPos()[0])][p.convertCoords(
                    p.newPos()[1])] = board.board[p.convertCoords(p.currentPos()[0])][p.convertCoords(
                    p.currentPos()[1])];
            board.board[p.convertCoords(p.currentPos()[0])][p.convertCoords(
                    p.currentPos()[1])] = (ChessPieces *) (new Empty());

            moveValid = false;
            // switches piece with valid location

        } else {
            moveValid = true;
        }
    }
    board.outputBoard();
}
