//
// Created by olidiaks on 10.12.2025.
//

#include "autonomousMode.h"

FILE *openOutputFileAndHandleError(char *filePath) {
    printf("%s\n", filePath);
    FILE *output_file = fopen(filePath, "w");
    if (output_file == NULL) {
        printf(
            "Error opening output file\nProbably path to given file is incorrect or program do not have enough permission for access.\n");
        exit(3);
    }
    return output_file;
}

FILE *openInputFileAndHandleError(char *filePath) {
    printf("%s\n", filePath);
    FILE *inputFile = fopen(filePath, "r");
    if (inputFile == NULL) {
        printf(
            "Error opening input file\nProbably path to given file is incorrect or program do not have enough permission for access.\n");
        exit(3);
    }
    return inputFile;
}

char readFile(FILE *givenFile) {
    int c;
    while ((c = getc(givenFile)) != EOF) {
        printf("%c \n", c);
    }
}
void loadUs(struct GameState *game_state, FILE *input_file) {}
