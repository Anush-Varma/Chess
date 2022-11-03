//
// Created by anush on 07/09/2022.
//

#ifndef CHESS_2_0_GAME_H
#define CHESS_2_0_GAME_H


#include "Board.h"

class Game {
public:
    Game();
private:
    void gameStart();
    void setupBoard(Board board);

};


#endif //CHESS_2_0_GAME_H
