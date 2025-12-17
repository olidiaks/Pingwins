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
        printf("Error opening output file\nProbably path to given file is incorrect or program do not have enough "
               "permission for access.\n");
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
        printf("Error opening input file\nProbably path to given file is incorrect or program do not have enough "
               "permission for access.\n");
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
bool loadPlayers(struct GameState *game_state, FILE *input_file) {
    bool isUsOnList = false;
    int idCount = 0;

    while (1) {
        char *name = NULL;
        int id, score;
        int fscanfStatus = fscanf(input_file, "%ms %d %d", name, &id, &score);
        if (fscanfStatus == EOF) {
            break;
        }
        if (fscanfStatus != 3) {
            printf("Players should be in order of player_nick_name id score and they are not in that order.");
            exit(2);
        }
        if (name == game_state->teamName) {
            isUsOnList = true;
            game_state->currentPlayer = id - 1;
        }
        if (idCount == id - 1) {
            idCount++;
            game_state->Players = realloc(game_state->Players, idCount * sizeof(struct Player));
            if (game_state->Players == NULL) {
                printf("Not enough memory to load players from file.");
                exit(3);
            }
        }

        game_state->Players[id - 1].currentScore = score;
        free(name);
    }
    printf("Successfully loaded players from file.");
    return isUsOnList;
}
