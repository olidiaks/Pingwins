//
// Created by olidiaks on 17.12.2025.
//

#include "autonomusMovement.h"


void autonomousMovement(struct GameState *gameState, char inputFilePath[], char outputFilePath[], char nameOfUs[]) {
    FILE *inputFile = openInputFileAndHandleError(inputFilePath);

    FILE *outputFile = openOutputFileAndHandleError(outputFilePath);

    readFile(inputFile);
}
