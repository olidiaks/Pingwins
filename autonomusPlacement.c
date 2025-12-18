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

    placePenguinAutomaticli(gameState);

    FILE *outputFile = openOutputFileAndHandleError(outputFilePath);
    writeBoardToFile(outputFile, gameState);
    fclose(outputFile);
}
void placePenguinAutomaticli(struct GameState *gameState) {
    do {
        gameState->Players[gameState->currentPlayer].x = rand() % gameState->xBoardSize;
        gameState->Players[gameState->currentPlayer].y = rand() % gameState->yBoardSize;
    } while (!(isCoordinateValid(gameState) && isPlacementValid(gameState)));
    placePenguin(gameState);
    collectFish(gameState);
}
