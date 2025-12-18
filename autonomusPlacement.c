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
    readFile(inputFile, gameState);
    fclose(inputFile);

    inputFile = fopen(inputFilePath, "r");
    loadPlayers(gameState, inputFile);

    fclose(inputFile);

    countPenguins(gameState, num_of_penguins_int);

    placePenguinAutomatically(gameState);
    FILE *outputFile = openOutputFileAndHandleError(outputFilePath);
    writeBoardToFile(outputFile, gameState);
    printf("File has been written into.\n");
    fclose(outputFile);
}


void placePenguinAutomatically(struct GameState *gameState) {
    for (int i = 0; i < gameState->xBoardSize; ++i) {
        for (int j = 0; j < gameState->yBoardSize; ++j) {
            if (gameState->Board[i][j].amountOfFish == 1) {
                int current_player = gameState->currentPlayer;
                gameState->Players[current_player].x = i;
                gameState->Players[current_player].y = j;
                gameState->Board[i][j].idPlayer = current_player + 1;
                collectFish(gameState);
                return;
            }
        }
    }
    printf("Imposible to place peenguin.\n");
    exit(1);
}
