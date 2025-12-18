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

            fprintf(outputFile, "%d%d ", currentField.amountOfFish, currentField.idPlayer);
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
void execute_player_move(struct GameState *gameState, int currentX, int currentY, int lastX, int lastY) {
    gameState->Players[gameState->currentPlayer].x = currentX;
    gameState->Players[gameState->currentPlayer].y = currentY;
    gameState->Board[currentX][currentY].idPlayer = gameState->currentPlayer + 1;
    gameState->Board[lastX][lastY].idPlayer = 0;
    collectFish(gameState);
    printf("Succesfule move was done!\n");
    return;
}
void movePenguinAutomaticli(struct GameState *gameState) {
    for (int x = 0; x < gameState->xBoardSize; ++x) {
        for (int y = 0; y < gameState->yBoardSize; ++y) {
            if (gameState->Board[x][y].amountOfFish == gameState->currentPlayer) {
                if (x > 0 && gameState->Board[x - 1][y].amountOfFish > 0) {
                    execute_player_move(gameState, x - 1, y, x, y);
                    return;
                }
                if (x < gameState->xBoardSize - 1 && gameState->Board[x + 1][y].amountOfFish > 0) {
                    execute_player_move(gameState, x + 1, y, x, y);
                    return;
                }
                if (y > 0 && gameState->Board[x][y - 1].amountOfFish > 0) {
                    execute_player_move(gameState, x, y - 1, x, y);
                    return;
                }
                if (y < gameState->yBoardSize - 1 && gameState->Board[x][y + 1].amountOfFish > 0) {
                    execute_player_move(gameState, x, y + 1, x, y);
                    return;
                }
            }
        }
    }
    printf("Cannot make any move.\n");
    exit(1);
}
