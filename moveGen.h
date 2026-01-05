//
// Created by theVo on 1/5/2026.
//

#ifndef PROJECT_MOVEGEN_H
#define PROJECT_MOVEGEN_H

#include "GameState.h"

struct Move {
    int penguinIdx;

    int toX;
    int toY;

    int fromX;
    int fromY;

    int moveValue;
};

int evaluateBoard(struct GameState *gs);

Move* generateAllLegalMoves(struct GameState *gs, int *count);

#endif //PROJECT_MOVEGEN_H