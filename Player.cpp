//
// Created by anush on 09/09/2022.
//

#include "Player.h"
#include "iostream"

Player::Player() {}

void Player::endTurn() {
    std::cout << "end turn" << std::endl;
}
void Player::startTurn() {
    std::cout << "start turn" << std::endl;
    gameStart();
}

void Player::gameStart() {
    std::cout << "Current Turn Player 1 (White to move)" << std::endl;
    std::cout << "Key: B - Black Piece"
                 " W - White Piece"
                 " P - Pawn"
                 " R - Rook"
                 " N - Knight"
                 " B - Bishop"
                 " Q - Queen"
                 " K - King"
                 " E - Empty" << std::endl;
    std::cout << std::endl;
    bool correctInput = true;
    while (correctInput) {
        try {
            std::cout << "Enter which piece to move example(a2): " << std::endl;

            std::cin >> currentPosition;

            correctInput = false;
        }catch (std::exception &e)
        {
            std::cout << "Incorrect input" << std::endl;
            correctInput = true;
        }
    }

    setCurrentPosition(currentPosition);


    correctInput = true;

    while (correctInput) {
        try {
            std::cout << "Enter where to move piece example(a3): " << std::endl;
            std::cin >> newPosition;
            correctInput = false;
        }catch (std::exception &e)
        {
            std::cout << "Incorrect input" << std::endl;
            correctInput = true;
        }
    }
    setNewPosition(newPosition);

}

std::string Player::currentPos() {
    return currentPosition;
}

std::string Player::newPos() {
    return newPosition;
}

void Player::setCurrentPosition(std::string newLocation) {
    currentPosition = newLocation;
}

void Player::setNewPosition(std::string newLocation) {
    newPosition = newLocation;
}

int Player::convertCoords(char coord) {
    switch (coord) {
        case 'a':
            return 0;
        case 'b':
            return 1;
        case 'c':
            return 2;
        case 'd':
            return 3;
        case 'e':
            return 4;
        case 'f':
            return 5;
        case 'g':
            return 6;
        case 'h':
            return 7;
        case '1':
            return 7;
        case '2':
            return 6;
        case '3':
            return 5;
        case '4':
            return 4;
        case '5':
            return 3;
        case '6':
            return 2;
        case '7':
            return 1;
        case '8':
            return 0;
        default:
            return 1000;
    }
}