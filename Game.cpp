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
    gameStart(board, p1);
}

void Game::gameStart(Board &board, Player p1) {
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




    //note# Change code to remove duplicate for p1 turn and p2 turn and generalise it


    correctInput = true;
    std::cout << std::endl;
    bool moveValid = true;
    while(moveValid) {
    board.outputBoard();
    p1.startTurn();
        if (board.board[p1.convertCoords(p1.currentPos()[0])][p1.convertCoords(p1.currentPos()[1])]->move(
                p1.convertCoords(p1.newPos()[1]), p1.convertCoords(p1.newPos()[0]),
                board.board[p1.convertCoords(p1.newPos()[1])][p1.convertCoords(p1.newPos()[0])]->getColour(),
                board.board)) //Checks if player1 move is valid
        {

            board.board[p1.convertCoords(p1.newPos()[0])][p1.convertCoords(
                    p1.newPos()[1])] = board.board[p1.convertCoords(p1.currentPos()[0])][p1.convertCoords(
                    p1.currentPos()[1])];
            board.board[p1.convertCoords(p1.currentPos()[0])][p1.convertCoords(
                    p1.currentPos()[1])] = (ChessPieces *) (new Empty());

            moveValid = false;

        } else {
            moveValid = true;
        }
    }
    board.outputBoard();




}

