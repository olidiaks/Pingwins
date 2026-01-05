//
// Created by theVo on 1/5/2026.
//

#include "moveGen.h"

#define WEIGHT_FISH 1000
#define WEIGHT_MOBILITY 10

int isTileFree(struct GameState *gs, int x, int y) {
    return (gs->Board[x][y].amountOfFish > 0 && gs->Board[x][y].idPenguin == -1);
}

int getAllPossibleMoves(struct GameState *gs, int playerId, int penguinIndex, int x, int y) {

    int mapBorderX = gs->xBoardSize;
    int mapBorderY = gs->yBoardSize;
    int possibleMoves = 0;

    for (int i = x - 1; i >= 0; i--) {

        if (isTileFree(gs, i, y)) possibleMoves++;
        else break;
    }

    for (int i = x + 1; i < mapBorderX; i++) {

        if (isTileFree(gs, i, y)) possibleMoves++;
        else break;
    }

    for (int i = y - 1; i >= 0; i--) {

        if (isTileFree(gs, x, i)) possibleMoves++;
        else break;
    }

    for (int i = y + 1; i < mapBorderY; i++) {

        if (isTileFree(gs, x, i)) possibleMoves++;
        else break;
    }

    return possibleMoves;
}

int evaluateBoard(struct GameState *gs) {

    int ownFish = gs->Players->currentScore;
    int ownPossibleMoves = 0;

    int biggestOpponentScore = 0;
    //int mostOpponentFish = INT_MIN;
    //int mostOpponentPossibleMoves = INT_MIN;

    for (int i = 0; i < gs->numOfPlayers; i++ ) {
        if (i == gs->currentPlayer) {

            for (int penguinIndex = 0; penguinIndex < gs->numOfPenguinsPerPlayer; penguinIndex++) {

                int penguinPositionX = gs->Players[i].penguins[penguinIndex].x;
                int penguinPositionY = gs->Players[i].penguins[penguinIndex].y;

                ownPossibleMoves += isMoveValidExtended(gs, i, penguinIndex, penguinPositionX, penguinPositionY);
            }

            continue;
        }

        int opponentFish = gs->Players[i].currentScore;
        //mostOpponentFish = opponentFish > mostOpponentFish && opponentFish || mostOpponentFish;

        int opponentMoves = 0;
        for (int penguinIndex = 0; penguinIndex < gs->numOfPenguinsPerPlayer; penguinIndex++) {

            int penguinPositionX = gs->Players[i].penguins[penguinIndex].x;
            int penguinPositionY = gs->Players[i].penguins[penguinIndex].y;

            opponentMoves += isMoveValidExtended(gs, i, penguinIndex, penguinPositionX, penguinPositionY);
        }

        int opponentScore = (opponentFish * WEIGHT_FISH) + (ownPossibleMoves * WEIGHT_MOBILITY);
        if (opponentScore > biggestOpponentScore)
            biggestOpponentScore = opponentScore;
        //mostOpponentPossibleMoves = opponentMoves > mostOpponentPossibleMoves && opponentMoves || mostOpponentPossibleMoves;
    }

    int ownScore = (ownFish * WEIGHT_FISH) + (ownPossibleMoves * WEIGHT_MOBILITY);
    return ownScore - biggestOpponentScore;
};

struct Move registerMove(struct GameState *gs, int plrId, int penguinIndex, int x, int y) {

    struct Move move;
    int penguinPositionX = gs->Players[plrId].penguins[penguinIndex].x;
    int penguinPositionY = gs->Players[plrId].penguins[penguinIndex].y;

    move.fromX = penguinPositionX;
    move.fromY = penguinPositionY;
    move.toX = x;
    move.toY = y;
    move.moveValue = 0;
    move.penguinIdx = penguinIndex;
    move.playerId = plrId;

    return move;
}

struct Move* generateAllLegalMoves(struct GameState *gs, int *count, int playerId) {

    *count = 0;

    for (int j = 0; j < gs->numOfPenguinsPerPlayer; j++) {
        int startX = gs->Players[playerId].penguins[j].x;
        int startY = gs->Players[playerId].penguins[j].y;

        if (startX == -1) continue;

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        for (int d = 0; d < 4; d++) {

            for (int step = 1; ; step++) {
                int newX = startX + (dx[d] * step);
                int newY = startY + (dy[d] * step);

                if (isTileFree(gs, newX, newY)) {
                    (*count)++;
                } else {
                    break;
                }
            }
        }
    }

    struct Move *moveTable = malloc((*count) * sizeof(Move));
    if (moveTable == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(3);
    }

    int moveIdx = 0;

    for (int j = 0; j < gs->numOfPenguinsPerPlayer; j++) {
        int startX = gs->Players[playerId].penguins[j].x;
        int startY = gs->Players[playerId].penguins[j].y;

        if (startX == -1) continue;

        int dx[] = {0, 0, -1, 1};
        int dy[] = {-1, 1, 0, 0};

        for (int d = 0; d < 4; d++) {
            for (int step = 1; ; step++) {
                int newX = startX + (dx[d] * step);
                int newY = startY + (dy[d] * step);

                if (isTileFree(gs, newX, newY)) {

                    moveTable[moveIdx] = registerMove(gs, playerId, moveIdx, newX, newY);
                    moveIdx++;
                } else {
                    break;
                }
            }
        }
    }

    return moveTable;
};