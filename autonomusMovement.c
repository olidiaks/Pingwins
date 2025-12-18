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

            fprintf(outputFile, "%d%d ", currentField.amountOfFish / 10, playerDigit);
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
void execute_player_move(struct GameState *gameState, int x, int y) {
    gameState->Board[x][y].idPlayer = gameState->currentPlayer + 1;
    collectFish(gameState);
    printf("Succesfule move was done!\n");
    return;
}
void movePenguinAutomaticli(struct GameState *gameState) {
    for (int x = 0; x < gameState->xBoardSize; ++x) {
        for (int y = 0; y < gameState->yBoardSize; ++y) {
            if (gameState->Board[x][y].amountOfFish == gameState->currentPlayer) {
                if (x > 0 && gameState->Board[x - 1][y].amountOfFish > 0) {
                    execute_player_move(gameState, x - 1, y);
                    return;
                }
                if (x < gameState->xBoardSize - 1 && gameState->Board[x + 1][y].amountOfFish > 0) {
                    execute_player_move(gameState, x + 1, y);
                    return;
                }
                if (y > 0 && gameState->Board[x][y - 1].amountOfFish > 0) {
                    execute_player_move(gameState, x, y - 1);
                    return;
                }
                if (y < gameState->yBoardSize - 1 && gameState->Board[x][y + 1].amountOfFish > 0) {
                    execute_player_move(gameState, x, y + 1);
                    return;
                }
            }
        }
    }
    printf("Cannot make any move.\n");
    exit(1);
}
