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
    void endGameCheck(Board &board, Player p, char colour);
    bool isKingAttackedFromDiagonal (Board &board, Player p, char colour);
    bool isKingAttackedFromHorOrVert(Board &board, Player p, char colour);
    bool isKingAttackedFromKnight(Board &board, Player p, char colour);
    bool isKingAbleToMoveUnderCheck(Board &board, Player p, char colour);
    bool blockingPiecesExist(Board &board, Player p, char colour);
    bool canPieceBeCaptured(Board &board, Player p, char colour);
    void checkMove(Board &board, Player p1);

};


#endif //CHESS_2_0_GAME_H
