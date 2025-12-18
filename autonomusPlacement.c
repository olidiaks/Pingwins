//
// Created by olidiaks on 17.12.2025.
//

#include "autonomusPlacement.h"

void autonomousPlacement(struct GameState *gameState, char inputFilePath[], char outputFilePath[], char nameOfUs[]) {
    FILE *inputFile = openInputFileAndHandleError(inputFilePath);
    readFile(inputFile);
    fclose(inputFile);

    inputFile = fopen(inputFilePath, "r");
    loadPlayers(gameState, inputFile);

    fclose(inputFile);

    FILE *outputFile = openOutputFileAndHandleError(outputFilePath);
    fclose(outputFile);
}

