//
// Created by olidiaks on 10.12.2025.
//

#include "autonomousMode.h"

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
    int c;
    while ((c = getc(givenFile)) != EOF) {
        printf("%c \n", c);
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
