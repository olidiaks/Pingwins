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
