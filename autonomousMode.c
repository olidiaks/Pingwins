//
// Created by olidiaks on 10.12.2025.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFile(FILE* board)
{
    printf("%p \n", board);
}

FILE *openInputFileAndHandleError(char *filePath) {
    FILE *inputFile = fopen(filePath, "r");
    if (inputFile == NULL) {
        printf(
            "Error opening input file\nProbably path to gaven file is incorrect or program do not have enough permission for access.\n");
        exit(3);
    }
    return inputFile;
}

FILE*openOutputFileAndHandleError(char *filePath) {
    FILE *output_file = fopen(filePath, "w");
    if (output_file == NULL)
    {
        printf(
            "Error opening output file\nProbably path to gaven file is incorrect or program do not have enough permission for access.\n");
        exit(3);
    }
    return output_file;
}

void autonomous_placement(struct GameState *gameState, char inputFilePath[], char outputFilePath[]) {
    FILE *inputFile = openInputFileAndHandleError(inputFilePath);

    FILE *outputFile = openOutputFileAndHandleError(outputFilePath);

    int c;
    while ((c = getc(inputFile)) != EOF) {
        printf("%d \n", c);
    }
}

void autonomous_movement(struct GameState *gameState, char inputFilePath[], char outputFilePath[]) {
    FILE*inputFile = openInputFileAndHandleError(inputFilePath);

    FILE *outputFile = openOutputFileAndHandleError(outputFilePath);
}
