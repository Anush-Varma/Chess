//
// Created by anush on 09/09/2022.
//

#ifndef CHESS_2_0_PLAYER_H
#define CHESS_2_0_PLAYER_H
#include "iostream"

class Player {
public:
    Player();
    void startTurn();
    void endTurn();
    std::string currentPos();
    std::string newPos();
    int convertCoords(char coord);
    std::string currentPosition = "Empty";
    std::string newPosition = "Empty";
private:

    void gameStart();
    void setCurrentPosition(std::string currentPosition);
    void setNewPosition(std::string newPosition);

};


#endif //CHESS_2_0_PLAYER_H
