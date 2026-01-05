//
// Created by theVo on 1/5/2026.
//

#include "moveGen.h"

#define WEIGHT_FISH 1000
#define WEIGHT_MOBILITY 10

int isTileFree(struct GameState *gs, int x, int y) {
    return (gs->Board[x][y].amountOfFish > 0 && gs->Board[x][y].idPenguin == -1);
}

int isMoveValidExtended(struct GameState *gs, int playerId, int penguinIndex, int x, int y) {

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

                int penguinPositionX = gs->Players->penguins[penguinIndex].x;
                int penguinPositionY = gs->Players->penguins[penguinIndex].y;

                ownPossibleMoves += isMoveValidExtended(gs, i, penguinIndex, penguinPositionX, penguinPositionY);
            }

            continue;
        }

        int opponentFish = gs->Players[i].currentScore;
        //mostOpponentFish = opponentFish > mostOpponentFish && opponentFish || mostOpponentFish;

        int opponentMoves = 0;
        for (int penguinIndex = 0; penguinIndex < gs->numOfPenguinsPerPlayer; penguinIndex++) {

            int penguinPositionX = gs->Players->penguins[penguinIndex].x;
            int penguinPositionY = gs->Players->penguins[penguinIndex].y;

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

//struct Move* generateAllLegalMoves(struct GameState *gs, int *count, int playerId) {


//};