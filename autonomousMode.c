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

    int rows, cols;
    if (!checkHeader(inputFile, &rows, &cols)) {
        printf("Error opening output file\nHeader malformed.\n");
        exit(2);
    }

    if (!checkDimensions(inputFile, rows, cols)) {
        printf("Error opening output file\nDimension - reported size mismatch.\n");
        exit(2);
    }

    if (!checkRectangularConsistency(inputFile)) {
        printf("Error opening output file\nBoard malformed.\n");
        exit(2);
    }

    if (!checkZeroConstraint(inputFile)) {
        printf("Error opening output file\nCritical placement error.\n");
        exit(2);
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

    char c;
    bool isUsOnList = false;
    int idCount = 9;
    int linesToSkip = 0;
    int n = 0;

    gameState.Players = malloc(sizeof(struct Player) * 9);
    if (gameState.Players == NULL) {
        printf("Not enough memory to load players from file.\n");
        exit(3);
    }

    if (fscanf(input_file, "%d %d", &linesToSkip, &n) != 2) {
        printf("Error: Could not read the number of header lines to skip.\n");
        exit(2);
    }


    for (int i = 0; i <= linesToSkip; i++) {
        while ((c = fgetc(input_file)) != '\n' && c != EOF)
            printf("%c", c);
        printf("\n");
    }

    while (1) {
        char *name = NULL;
        int id, score;

        int fscanfStatus = fscanf(input_file, "%ms %d %d", &name, &id, &score);

        if (fscanfStatus == EOF) {
            if (name)
                free(name);
            break;
        }

        if (fscanfStatus != 3) {
            printf("Players should be in order of player_nick_name id score.\n");
            if (name)
                free(name);
            exit(2);
        }

        if (strcmp(name, game_state->teamName) == 0) {
            game_state->currentPlayer = id - 1;
            isUsOnList = true;
        }

        if (idCount == id - 1) {
            idCount++;
            game_state->Players[id].name = name;
        }

        game_state->Players[id - 1].currentScore = score;

        free(name);
    }

    printf("Successfully loaded players from file.\n");

    if (!isUsOnList) {
        game_state->Players[game_state->currentPlayer].name = game_state->teamName;
        game_state->Players[game_state->currentPlayer].currentScore = 0;
    }
}
