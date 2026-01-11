//
// Created by olidiaks on 17.12.2025.
//

#include "autonomusMovement.h"

#include <limits.h>

#include "moveGen.h"
#include "playerActions.h"
#include <math.h>

void executePlayerMove(struct GameState *gameState, int currentX, int currentY, int lastX, int lastY) {
    gameState->Players[gameState->currentPlayer].x = currentX;
    gameState->Players[gameState->currentPlayer].y = currentY;
    gameState->Board[currentX][currentY].idPlayer = gameState->currentPlayer + 1;
    gameState->Board[lastX][lastY].idPlayer = 0;
    collectFish(gameState);
    printf("Successfully move was done!\n");
}

void movePenguinAutomatically(struct GameState *gameState) {
    for (int x = 0; x < gameState->xBoardSize; ++x) {
        for (int y = 0; y < gameState->yBoardSize; ++y) {
            if (gameState->Board[x][y].idPlayer == gameState->currentPlayer + 1) {
                if (x > 0 && gameState->Board[x - 1][y].amountOfFish > 0) {
                    executePlayerMove(gameState, x - 1, y, x, y);
                    return;
                }
                if (x < gameState->xBoardSize - 1 && gameState->Board[x + 1][y].amountOfFish > 0) {
                    executePlayerMove(gameState, x + 1, y, x, y);
                    return;
                }
                if (y > 0 && gameState->Board[x][y - 1].amountOfFish > 0) {
                    executePlayerMove(gameState, x, y - 1, x, y);
                    return;
                }
                if (y < gameState->yBoardSize - 1 && gameState->Board[x][y + 1].amountOfFish > 0) {
                    executePlayerMove(gameState, x, y + 1, x, y);
                    return;
                }
            }
        }
    }
    printf("Cannot make any move.\n");
    exit(1);
}

void autonomousMovement(struct GameState *gameState, char inputFilePath[], char outputFilePath[], char nameOfUs[]) {
    FILE *inputFile = openInputFileAndHandleError(inputFilePath);
    fclose(inputFile);

    inputFile = fopen(inputFilePath, "r");
    loadBoard(inputFile, gameState);
    fclose(inputFile);

    inputFile = fopen(inputFilePath, "r");
    loadPlayers(gameState, inputFile);
    fclose(inputFile);

    loadPenguins(gameState);
    showBoard(gameState);

    validatePenguinCountConsistency(gameState);

    gameState->Players[gameState->currentPlayer].currentPenguin = 0;
    printf("Pointer to penguins: %p\n", gameState->Players[gameState->currentPlayer].penguins);

    struct Move bestMove = calculateBestMove(gameState,20);
    //printf("x\n");
    gameState->Players[gameState->currentPlayer].x= bestMove.toX;
    //printf("x\n");
    gameState->Players[gameState->currentPlayer].y= bestMove.toY;
    //printf("x\n");
    movePenguin(gameState);

    FILE *outputFile = openOutputFileAndHandleError(outputFilePath);
    writeBoardToFile(outputFile, gameState);

    fclose(outputFile);
}

struct Move calculateBestMove(struct GameState *gameState, int depth) {
    struct Move bestMove;

    bestMove.fromX = gameState->Players[gameState->currentPlayer].penguins[gameState->Players[gameState->currentPlayer].currentPenguin].x;
    bestMove.fromY = gameState->Players[gameState->currentPlayer].penguins[gameState->Players[gameState->currentPlayer].currentPenguin].y;
    bestMove.playerId = gameState->currentPlayer;
    bestMove.moveValue = 0;
    bestMove.penguinIdx = -1;

    int curPlayer = gameState->currentPlayer;
    int curPenguin = gameState->Players[curPlayer].currentPenguin;
    int x = gameState->Players[curPlayer].x;
    int y = gameState->Players[curPlayer].y;

    for (int i = 0;i < countPossibleMoves(gameState, curPlayer, curPenguin,x,y);i++) { //all possible moves
        struct GameState *gameStateCopy = deepCloneGameState(gameState);
        struct Move *allMoves = generateAllLegalMoves(gameStateCopy,0,curPlayer);
        gameStateCopy->Players[curPlayer].x = allMoves[i].toX;
        gameStateCopy->Players[curPlayer].x = allMoves[i].toY;
        movePenguin(gameStateCopy);
        int score = evaluateBoard(gameStateCopy);
        alphaBeta(gameStateCopy,depth,INT_MAX,INT_MIN,false);
        if (score > bestMove.moveValue) {
            bestMove.moveValue = score;
            //bestMove.penguinIdx = ;
        }
        freeGameState(gameStateCopy);
    }
    return bestMove;

}

int alphaBeta(struct GameState *gameState, int depth, int alpha, int beta, bool isMax) {
    float maxEval;
    float minEval;
    int curPlayer = gameState->currentPlayer;
    int curPenguin = gameState->Players[curPlayer].currentPenguin;
    int x = gameState->Players[curPlayer].x;
    int y = gameState->Players[curPlayer].y;
    if (depth == 0 || isAnyMoveForCurrentPenguinAvailable(gameState)) {
        return evaluateBoard(gameState);
    }
    else {
        //generateAllLegalMoves();
        if (isMax) { //opponent turn
            isMax = true;
            maxEval = INT_MIN;
            for (int i = 0;i < countPossibleMoves(gameState, curPlayer, curPenguin,x,y);i++) {
                struct GameState *gameStateCopy = deepCloneGameState(gameState);
                movePenguin(gameStateCopy);
                alphaBeta(gameStateCopy, depth -1, alpha, beta, false);
                if (maxEval > evaluateBoard(gameStateCopy)) {
                    maxEval = evaluateBoard(gameStateCopy);
                }
                freeGameState(gameStateCopy);
                if (alpha > maxEval) {
                    alpha = maxEval;
                }
                if (beta <= alpha) {
                    break;
                }
            }
            return maxEval;
        }
        else {
            //our turn
            isMax = false;
            minEval = INT_MAX;
            for (int i = 0;i < countPossibleMoves(gameState, curPlayer, curPenguin,x,y);i++) {
                struct GameState *gameStateCopy = deepCloneGameState(gameState);
                movePenguin(gameStateCopy);
                alphaBeta(gameState, depth -1, alpha, beta, true);
                if (minEval < evaluateBoard(gameStateCopy)) {
                    minEval = evaluateBoard(gameStateCopy);
                }
                freeGameState(gameStateCopy);
                if (beta < minEval) {
                    beta = minEval;
                }
                if (beta <= alpha) {
                    break;
                }
                return minEval;
            }
        }
    }
}