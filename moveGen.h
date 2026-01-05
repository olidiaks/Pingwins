//
// Created by theVo on 1/5/2026.
//

#ifndef PROJECT_MOVEGEN_H
#define PROJECT_MOVEGEN_H

#include "GameState.h"

struct Move {
    int playerId;
    int penguinIdx;

    int toX;
    int toY;

    int fromX;
    int fromY;

    int moveValue;
};

int isTileFree(struct GameState *gs, int x, int y);

int getAllPossibleMoves(struct GameState *gs, int playerId, int penguinIndex, int x, int y);

int evaluateBoard(struct GameState *gs);

struct Move registerMove(struct GameState *gs, int plrId, int penguinIndex, int x, int y);

struct Move* generateAllLegalMoves(struct GameState *gs, int *count, int playerId);

#endif //PROJECT_MOVEGEN_H