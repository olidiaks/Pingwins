//
// Created by olidiaks on 17.12.2025.
//

#include "autonomusMovement.h"

#include "playerActions.h"


void executePlayerMove(struct GameState *gameState, int currentX, int currentY, int lastX, int lastY) {
    gameState->Players[gameState->currentPlayer].x = currentX;
    gameState->Players[gameState->currentPlayer].y = currentY;
    gameState->Board[currentX][currentY].idPlayer = gameState->currentPlayer + 1;
    gameState->Board[lastX][lastY].idPlayer = 0;
    collectFish(gameState);
    printf("Succesfule move was done!\n");
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

    movePenguinAutomaticli(gameState);

    FILE *outputFile = openOutputFileAndHandleError(outputFilePath);
    writeBoardToFile(outputFile, gameState);

    fclose(outputFile);
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
