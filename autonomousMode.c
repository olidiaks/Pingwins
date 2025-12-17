//
// Created by olidiaks on 10.12.2025.
//

#include "autonomousMode.h"

#include "boardGeneration.h"
#include "main.h"

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
    char line[127];
    int counter = 0;
    int rows = 0, cols = 0;
    while (fgets(line,127,givenFile)) {
        printf("%s \n", line);
        if (counter == 0) {
            // reading board dimensions
            rows = atoi(&line[3]);
            cols = atoi(&line[0]);

            gameState.xBoardSize = rows;
            gameState.yBoardSize = cols;
            generateBoard(&gameState);
        }
        else if (counter <= cols) {
            // reading how the board is constructed
            char * coordinates;
            coordinates = strtok(line, " ");
            while (coordinates != NULL) {
                char *boardspot = coordinates;
                //printf("%s \n",boardspot);
                for (int i = 0; i < cols; i++) {
                    gameState.Board[counter-1][i].amountOfFish = atoi(&boardspot[0]);
                }
                coordinates = strtok(NULL, " ");
            }
        }
        counter++;
    }
    printf("The number of rows is %d, the number of columns is %d \n",rows,cols);
    for (int i = 0; i < gameState.yBoardSize; i++) {
        for (int j = 0; j < gameState.xBoardSize; j++) {
            printf("%d ",gameState.Board[i][j].amountOfFish);
        }
    }
}
void loadUs(struct GameState *game_state, FILE *input_file) {}
