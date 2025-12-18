//
// Created by olidiaks on 17.12.2025.
//

#include "autonomusMovement.h"

#include "playerActions.h"

void writeBoardToFile(FILE *outputFile, struct GameState *gameState) {
    if (outputFile == NULL) {
        fprintf(stderr, "Error: Invalid file pointer or game state.\n");
        return;
    }

    fprintf(outputFile, "%d %d\n", gameState->xBoardSize, gameState->yBoardSize);

    for (int i = 0; i < gameState->xBoardSize; i++) {
        for (int j = 0; j < gameState->yBoardSize; j++) {
            struct Field currentField = gameState->Board[i][j];

            int playerDigit = 0;
            if (currentField.idPlayer != -1) {
                playerDigit = currentField.idPlayer;
            }

            fprintf(outputFile, "%d%d ", currentField.amountOfFish/10, playerDigit);
        }

        fprintf(outputFile, "\n");
    }

    for (int k = 0; k < gameState->numOfPlayers; k++) {

        int displayID = k + 1;
        char *pName = (gameState->Players[k].name != NULL) ? gameState->Players[k].name : "Unknown";
        fprintf(outputFile, "%s %d %d\n", pName, displayID, gameState->Players[k].currentScore);
    }
}

void autonomousMovement(struct GameState *gameState, char inputFilePath[], char outputFilePath[], char nameOfUs[]) {
    FILE *inputFile = openInputFileAndHandleError(inputFilePath);

    FILE *outputFile = openOutputFileAndHandleError(outputFilePath);

    readFile(inputFile, gameState);

    writeBoardToFile(outputFile, gameState);

    fclose(inputFile);
    fclose(outputFile);
}
void movePenguinAutomaticli(struct GameState *gameState) {
    do {
        // TODO: DOkoniczyć to tak aby odnosił się jakoś do swojego pingwinka.
        gameState->Players[gameState->currentPlayer].x = rand() % gameState->xBoardSize;
        gameState->Players[gameState->currentPlayer].y = rand() % gameState->yBoardSize;
    } while (!(isCoordinateValid(gameState) && isMoveValid(gameState)));
    placePenguin(gameState);
    collectFish(gameState);
}
