//
// Created by anush on 07/09/2022.
//

#ifndef CHESS_2_0_GAME_H
#define CHESS_2_0_GAME_H

#include "Board.h"
#include "Player.h"

class Game {
public:
    Game();
private:
    void gameStart(Board &board, Player p1, Player p2);
    void endGameCheck(Board &board, Player p1, Player p2);
    void checkMove(Board &board, Player p1);

};


#endif //CHESS_2_0_GAME_H
