//
// Created by olidiaks on 17.12.2025.
//

#include "autonomusPlacement.h"

#include "autonomusMovement.h"
#include "placementInteractive.h"

void countPenguins(struct GameState *gameState, int numOfPengiuns) {
    int playerId = gameState->currentPlayer + 1;
    int counter = 0;

    for (int x = 0; x < gameState->xBoardSize; ++x) {
        for (int y = 0; y < gameState->yBoardSize; ++y) {
            if (gameState->Board[x][y].idPlayer == playerId) {
                counter++;
                if (counter == numOfPengiuns) {
                    printf("All penguins placed.\n");
                    exit(1);
                }
            }
        }
    }
}

void autonomousPlacement(struct GameState *gameState, char inputFilePath[], char outputFilePath[], char nameOfUs[],
                         char num_of_penguins[]) {
    char c = num_of_penguins[9];
    int num_of_penguins_int = atoi(&c);

    FILE *inputFile = openInputFileAndHandleError(inputFilePath);
    fclose(inputFile);

    inputFile = fopen(inputFilePath, "r");
    loadBoard(inputFile, gameState);
    fclose(inputFile);

    inputFile = fopen(inputFilePath, "r");
    loadPlayers(gameState, inputFile);
    fclose(inputFile);

    loadPenguins(gameState);

    countPenguins(gameState, num_of_penguins_int);

    placePenguinAutomatically(gameState);
    FILE *outputFile = openOutputFileAndHandleError(outputFilePath);
    writeBoardToFile(outputFile, gameState);
    printf("File has been written into.\n");
    fclose(outputFile);
}

void placePenguinAutomatically(struct GameState *gameState) {
    int bestX, bestY;
    int bestScore = 0;
    for (int x = 0; x < gameState->xBoardSize; ++x) {
        for (int y = 0; y < gameState->yBoardSize; ++y) {
            if (gameState->Board[x][y].amountOfFish == 1) {
                int score = scorePlacement(gameState, x, y);
                if (score > bestScore) {
                    bestScore = score;
                    bestX = x;
                    bestY = y;
                }
            }
        }
    }

    if (bestScore > 0) {
        int current_player = gameState->currentPlayer;
        gameState->Players[current_player].x = bestX;
        gameState->Players[current_player].y = bestY;
        gameState->Board[bestX][bestY].idPlayer = current_player + 1;
        collectFish(gameState);
    } else {
        printf("Didn't found any penguin to place.\n");
        exit(1);
    }
}

int scorePlacement(struct GameState *game_state, int x, int y) {
    if (0 <= x && x < game_state->xBoardSize && 0 <= y && y < game_state->yBoardSize &&
        !game_state->Board[x][y].amountOfFish) {
        return 0;
    }

    return scorePlacement(game_state, x - 1, y) + scorePlacement(game_state, x + 1, y) +
           scorePlacement(game_state, x, y - 1) + scorePlacement(game_state, x, y + 1) +
           game_state->Board[x][y].amountOfFish;
}
