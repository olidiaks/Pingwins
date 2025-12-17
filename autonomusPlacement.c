//
// Created by olidiaks on 17.12.2025.
//

#include "autonomusPlacement.h"

void autonomousPlacement(struct GameState *gameState, char inputFilePath[], char outputFilePath[]) {
    FILE *inputFile = openInputFileAndHandleError(inputFilePath);

    FILE *outputFile = openOutputFileAndHandleError(outputFilePath);

    readFile(inputFile);

}

