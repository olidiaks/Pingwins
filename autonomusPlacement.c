//
// Created by olidiaks on 17.12.2025.
//

#include "autonomusPlacement.h"

#include "autonomusMovement.h"
#include "placementInteractive.h"

void autonomousPlacement(struct GameState *gameState, char inputFilePath[], char outputFilePath[], char nameOfUs[]) {
    FILE *inputFile = openInputFileAndHandleError(inputFilePath);
    fclose(inputFile);
    inputFile = fopen(inputFilePath, "r");
    readFile(inputFile, gameState);
    fclose(inputFile);

    inputFile = fopen(inputFilePath, "r");
    loadPlayers(gameState, inputFile);

    fclose(inputFile);

    placePenguinAutomatically(gameState);
    FILE *outputFile = openOutputFileAndHandleError(outputFilePath);
    //("The file doesn't have any errors\n");
    writeBoardToFile(outputFile, gameState);
    printf("File has been written into.\n");
    fclose(outputFile);
}
void placePenguinAutomatically(struct GameState *gameState) {
    do {
        gameState->Players[gameState->currentPlayer].x = rand() % gameState->xBoardSize;
        gameState->Players[gameState->currentPlayer].y = rand() % gameState->yBoardSize;
    } while (!(isCoordinateValid(gameState) && isPlacementValid(gameState)));
    placePenguin(gameState);
    collectFish(gameState);
}
