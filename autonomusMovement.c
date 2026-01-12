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

    printf("Pointer to penguins: %p\n", gameState->Players[gameState->currentPlayer].penguins);

    struct Move bestMove = calculateBestMove(gameState,6);
    printf("Best move: fromX %d, fromY: %d, toX: %d, toY: %d, as %d, penguin id %d\n", bestMove.fromX, bestMove.fromY, bestMove.toX, bestMove.toY, bestMove.playerId, bestMove.penguinIdx);

    //gameState->Players[gameState->currentPlayer].currentPenguin = bestMove.penguinIdx;
    //printf("x\n");
    //gameState->Players[gameState->currentPlayer].x= bestMove.toX;
    //printf("x\n");
    //gameState->Players[gameState->currentPlayer].y= bestMove.toY;
    //printf("x\n");
    //movePenguin(gameState);
    makeMove(gameState, &bestMove);

    showBoard(gameState);

    FILE *outputFile = openOutputFileAndHandleError(outputFilePath);
    writeBoardToFile(outputFile, gameState);

    fclose(outputFile);
}

void makeMove(struct GameState *gs, struct Move *move) {

    gs->Board[move->fromX][move->fromY].idPlayer = -1;
    gs->Board[move->fromX][move->fromY].idPenguin = -1;

    gs->Board[move->toX][move->toY].idPlayer = move->playerId;
    gs->Board[move->toX][move->toY].idPenguin = move->penguinIdx;

    gs->Players[move->playerId].penguins[move->penguinIdx].x = move->toX;
    gs->Players[move->playerId].penguins[move->penguinIdx].y = move->toY;

    gs->Players[move->playerId].currentScore += move->capturedFish;
    gs->Board[move->toX][move->toY].amountOfFish = 0;

    gs->currentPlayer = (gs->currentPlayer + 1) % gs->numOfPlayers;
}

void unmakeMove(struct GameState *gs, struct Move *move) {

    gs->currentPlayer = (gs->currentPlayer - 1 + gs->numOfPlayers) % gs->numOfPlayers;

    gs->Board[move->toX][move->toY].amountOfFish = move->capturedFish;
    gs->Players[move->playerId].currentScore -= move->capturedFish;

    gs->Players[move->playerId].penguins[move->penguinIdx].x = move->fromX;
    gs->Players[move->playerId].penguins[move->penguinIdx].y = move->fromY;

    gs->Board[move->toX][move->toY].idPlayer = -1;
    gs->Board[move->toX][move->toY].idPenguin = -1;

    gs->Board[move->fromX][move->fromY].idPlayer = move->playerId;
    gs->Board[move->fromX][move->fromY].idPenguin = move->penguinIdx;
}

int alphaBeta(struct GameState *gs, int depth, int alpha, int beta, bool isMax) {
    if (depth == 0) return evaluateBoard(gs);

    int moveCount = 0;
    struct Move *moves = generateAllLegalMoves(gs, &moveCount, gs->currentPlayer);

    if (moveCount == 0) {
        free(moves);
        return evaluateBoard(gs);
    }

    int bestVal = isMax ? INT_MIN : INT_MAX;

    for (int i = 0; i < moveCount; i++) {
        makeMove(gs, &moves[i]);

        // Recursive call
        int val = alphaBeta(gs, depth - 1, alpha, beta, !isMax);

        unmakeMove(gs, &moves[i]);

        if (isMax) {
            if (val > bestVal) bestVal = val;
            if (val > alpha) alpha = val;
        } else {
            if (val < bestVal) bestVal = val;
            if (val < beta) beta = val;
        }

        if (beta <= alpha) break; // Pruning
    }

    free(moves);
    return bestVal;
}

struct Move calculateBestMove(struct GameState *gameState, int depth) {
    struct Move bestMove;
    bestMove.moveValue = INT_MIN;

    int moveCount = 0;
    struct Move *moves = generateAllLegalMoves(gameState, &moveCount, gameState->currentPlayer);

    if (moveCount == 0) {
        printf("No moves available!\n");
        exit(1);
    }

    // Root of Alpha-Beta
    for (int i = 0; i < moveCount; i++) {
        makeMove(gameState, &moves[i]);

        // We just played (Max), so next is Min (false)
        int score = alphaBeta(gameState, depth - 1, INT_MIN, INT_MAX, false);

        unmakeMove(gameState, &moves[i]);

        printf("Move %d -> (%d, %d) Score: %d\n", i, moves[i].toX, moves[i].toY, score);

        if (score > bestMove.moveValue) {
            bestMove = moves[i];
            bestMove.moveValue = score;
        }
    }

    free(moves);
    return bestMove;
}