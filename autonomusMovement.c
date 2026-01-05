//
// Created by olidiaks on 17.12.2025.
//

#include "autonomusMovement.h"

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
    readFile(inputFile, gameState);
    fclose(inputFile);

    inputFile = fopen(inputFilePath, "r");
    loadPlayers(gameState, inputFile);
    fclose(inputFile);

    movePenguinAutomatically(gameState);

    FILE *outputFile = openOutputFileAndHandleError(outputFilePath);
    writeBoardToFile(outputFile, gameState);

    fclose(outputFile);
}

void calculateBestMove(struct GameState *gameState, int depth) {
    int bestScore = -INFINITY;
    //struct Move bestMove = // change to struct Move
    //cloneGameState(gameState);
    //makeMoveSilent(altGameState);
    //alphaBeta(altGameState,1,0,0,false);
    // if (score > bestScore) {
    //     bestScore = score;
    //     bestMove[0] =
    // }
    //freeGameState();
    //return bestMove;

}

void alphaBeta(struct GameState *game_state, int depth, int alpha, int beta, bool isMax) {
    float maxEval;
    float minEval;
    if (depth == 0 || ) {
        return evaluateBoard();
    }
    else {
        generateAllLegalMoves();
        if (isMax) { //opponent turn
            isMax = true;
            maxEval = -INFINITY;
            //for loop going by every possible move generated above
                //clone state
                //make a move
                alphaBeta(game_state, depth +1, alpha, beta, false);
                //delete clone
                //update maxEval if the move is better
                // update alpha max(alpha,score)
                if (beta <= alpha) {
                    break;
            }
            return maxEval;
        }
        else { //our turn
            isMax = false;
            minEval = HUGE_VAL;
            //for loop going by every possible move generated above
                //clone state
                //make a move
                alphaBeta(game_state, depth +1, alpha, beta, true);
                //delete clone
                //update maxEval if the move is better
                // update beta min(beta,score)
                if (beta <= alpha) {
                    break;
                }
            return minEval;
        }

    }

}