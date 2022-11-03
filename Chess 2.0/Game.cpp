//
// Created by anush on 07/09/2022.
//

#include <iostream>
#include "Game.h"
#include "Board.h"
#include "Empty.h"

Game::Game() {
    Board board;
    gameStart();
    setupBoard(board);
}

void Game::gameStart() {
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
    std::cout << std::endl;

}

void Game::setupBoard(Board board) {
    for (int i = 0; i < board.board.size(); ++i) {
        for (int j = 0; j < board.board[i].size(); ++j) {
            board.board[i][j] = make_shared<Empty>();
        }
    }
}