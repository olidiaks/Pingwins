//
// Created by olidiaks on 10.12.2025.
//

#include "autonomousMode.h"

#include "boardGeneration.h"
#include "loadValidator.h"
#include "main.h"

FILE *openOutputFileAndHandleError(char *filePath) {
    printf("%s\n", filePath);
    FILE *output_file = fopen(filePath, "w");
    if (output_file == NULL) {
        printf(
            "Error opening output file\nProbably path to given file is incorrect or program do not have enough permission for access.\n");
        exit(3);
    }

    int rows, cols;
    if (!checkHeader(output_file, &rows, &cols)) {
        printf("Error opening output file\nHeader malformed.\n");
        exit(2);
    }

    if (!checkDimensions(output_file, rows, cols)) {
        printf("Error opening output file\nDimension - reported size mismatch.\n");
        exit(2);
    }

    if (!checkRectangularConsistency(output_file)) {
        printf("Error opening output file\nBoard malformed.\n");
        exit(2);
    }

    if (!checkZeroConstraint(output_file)) {
        printf("Error opening output file\nCritical placement error.\n");
        exit(2);
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
    const char *delimiters = " \r\n"; // Split by space, carriage return, or newline

    while (fgets(line, sizeof(line), givenFile)) {
        if (counter == 0) {
            if (sscanf(line, "%d %d", &rows, &cols) == 2) {
                gameState.xBoardSize = rows;
                gameState.yBoardSize = cols;

                generateVoidBoard(&gameState);
                printf("Map Dimensions found: %d rows, %d cols\n", rows, cols);
            }
        }

        else if (counter <= rows) {
            char *token = strtok(line, delimiters);
            int colIndex = 0;

            while (token != NULL && colIndex < cols) {
                gameState.Board[counter - 1][colIndex].amountOfFish = atoi(token);

                colIndex++;
                token = strtok(NULL, delimiters);
            }
        }
        counter++;
    }

    printf("\n--- Internal Check ---\n");
    for (int i = 0; i < gameState.xBoardSize; i++) {
        for (int j = 0; j < gameState.yBoardSize; j++) {
            printf("%02d ", gameState.Board[i][j].amountOfFish);
        }
        printf("\n");
    }
}
void loadUs(struct GameState *game_state, FILE *input_file) {}
