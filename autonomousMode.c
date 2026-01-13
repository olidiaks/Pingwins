//
// Created by olidiaks on 10.12.2025.
//

#include "autonomousMode.h"


void writeBoardToFile(FILE *outputFile, struct GameState *gameState) {
    if (outputFile == NULL) {
        fprintf(stderr, "Error: Invalid file pointer or game state.\n");
        return;
    }

    fprintf(outputFile, "%d %d\n", gameState->xBoardSize, gameState->yBoardSize);

    for (int i = 0; i < gameState->xBoardSize; i++) {
        for (int j = 0; j < gameState->yBoardSize; j++) {
            struct Field currentField = gameState->Board[i][j];

            fprintf(outputFile, "%d%d ", currentField.amountOfFish, currentField.idPlayer + 1);
        }

        fprintf(outputFile, "\n");
    }

    printf("Enumerating players, plr count: %d\n", gameState->numOfPlayers);
    for (int k = 0; k < 9; k++) {

        int displayID = k + 1;
        if (gameState->Players[k].name != NULL) {
            fprintf(outputFile, "%s %d %d\n", gameState->Players[k].name, displayID,
                    gameState->Players[k].currentScore);
        }
    }
}

FILE *openOutputFileAndHandleError(char *filePath) {
    printf("%s\n", filePath);
    FILE *output_file = fopen(filePath, "w");
    if (output_file == NULL) {
        printf("Error opening output file\nProbably path to given file is incorrect or program do not have enough "
               "permission for access.\n");
        exit(3);
    }
    // printf("The output file created as %s\n", filePath);
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

void loadBoard(FILE *givenFile, struct GameState *gameState) {
    char line[8192];
    int counter = 0;
    int rows = 0, cols = 0;
    const char *delimiters = " \r\n"; // Split by space, carriage return, or newline

    while (fgets(line, sizeof(line), givenFile)) {
        if (counter == 0) {
            if (sscanf(line, "%d %d", &rows, &cols) == 2) {
                gameState->xBoardSize = rows;
                gameState->yBoardSize = cols;

                generateVoidBoard(gameState);
                printf("Map Dimensions found: %d rows, %d cols\n", rows, cols);

                for (int r = 0; r < rows; r++) {
                    for (int c = 0; c < cols; c++) {
                        gameState->Board[r][c].idPenguin = -1;
                        gameState->Board[r][c].idPlayer = -1;
                    }
                }

            }
        }

        else if (counter <= rows) {
            char *token = strtok(line, delimiters);
            int colIndex = 0;

            while (token != NULL && colIndex < cols) {
                int amountOfFish = atoi(token) / 10;
                gameState->Board[counter - 1][colIndex].amountOfFish = amountOfFish;
                int idPlayer = atoi(token) % 10;
                gameState->Board[counter - 1][colIndex].idPlayer = idPlayer - 1;
                gameState->Board[counter - 1][colIndex].idPenguin = -1;
                colIndex++;
                token = strtok(NULL, delimiters);
            }
        }
        counter++;
    }

    printf("\n--- Internal Check ---\n");
    for (int i = 0; i < gameState->xBoardSize; i++) {
        for (int j = 0; j < gameState->yBoardSize; j++) {
            printf("%02d ", gameState->Board[i][j].amountOfFish);
        }
        printf("\n");
    }
    printf("\n");
}


void loadPlayers(struct GameState *game_state, FILE *input_file) {
    char buffer[256];
    bool isTeamNameOnList = false;
    int linesToSkip = 0;
    int n = 0;

    game_state->Players = calloc(9, sizeof(struct Player));
    if (game_state->Players == NULL) {
        fprintf(stderr, "Not enough memory to load players.\n");
        exit(3);
    }

    if (fscanf(input_file, "%d %d", &linesToSkip, &n) != 2) {
        fprintf(stderr, "Error: Could not read header.\n");
        exit(2);
    }

    fgetc(input_file);

    for (int i = 0; i < linesToSkip; i++) {
        if (fgets(buffer, sizeof(buffer), input_file) != NULL) {
            printf("%s", buffer);
        }
    }

    game_state->numOfPlayers = 0;
    int occupiedIDs[9] = {0};

    while (1) {
        char *name = NULL;
        int id, score;

        int fscanfStatus = fscanf(input_file, "%ms %d %d", &name, &id, &score);

        if (fscanfStatus == EOF)
            break;

        if (fscanfStatus != 3) {
            printf("Error: Invalid player format.\n");
            free(name);
            exit(2);
        }

        if (id < 1 || id > 9) {
            printf("Error: Player ID %d out of bounds.\n", id);
            free(name);
            exit(2);
        }

        int idx = id - 1;
        game_state->Players[idx].name = name;
        game_state->Players[idx].currentScore = score;
        game_state->Players[idx].currentPenguin = 0;

        occupiedIDs[idx] = 1;
        printf("Incrementing numPlrs: %d, -> %d\n", game_state->numOfPlayers, game_state->numOfPlayers + 1);
        game_state->numOfPlayers++;

        printf("Comparing two strings: %s, %s\n", name, game_state->teamName);
        if (strcmp(name, game_state->teamName) == 0) {
            game_state->currentPlayer = idx;
            isTeamNameOnList = true;
        }
    }

    if (!isTeamNameOnList) {
        int availIdx = -1;

        for (int i = 0; i < 9; i++) {
            if (occupiedIDs[i] == 0) {
                availIdx = i;
                break;
            }
        }

        if (availIdx == -1) {
            printf("All id's are oqupied so there is not place for us. Too many players\n");
            exit(2);
        }

        game_state->Players[availIdx].name = strdup(game_state->teamName);
        game_state->Players[availIdx].currentScore = 0;
        game_state->Players[availIdx].currentPenguin = 0;
        game_state->currentPlayer = availIdx;
        game_state->numOfPlayers++;
    }

    printf("Successfully loaded %d players.\n", game_state->numOfPlayers);
}

void validatePenguinCountConsistency(struct GameState *game_state) {
    int *currentPenguin = &game_state->Players[0].currentPenguin;
    int numOfPenguins = *currentPenguin;
    *(currentPenguin) = 0;
    for (int i = 1; i < game_state->numOfPlayers; i++) {
        currentPenguin = &game_state->Players[i].currentPenguin;
        if (numOfPenguins != *currentPenguin) {
            printf("Number of penguins for each player must be the same.\n");
            exit(2);
        }
        *currentPenguin = 0;
    }
    game_state->numOfPenguinsPerPlayer = numOfPenguins;
    printf("The number of penguins per player : %d \n",game_state->numOfPenguinsPerPlayer);
}

void loadPenguins(struct GameState *game_state) {
    for (int x = 0; x < game_state->xBoardSize; ++x) {
        for (int y = 0; y < game_state->yBoardSize; ++y) {
            int id_player = game_state->Board[x][y].idPlayer;
            if (id_player != -1) {
                int *current_penguin = &game_state->Players[id_player].currentPenguin;
                struct Penguin *penguinsArray = realloc(game_state->Players[id_player].penguins, sizeof(struct Penguin) * (*current_penguin + 1));
                if (penguinsArray == NULL) {
                    fprintf(stderr, "Not enough memory to load penguins.\n");
                    exit(3);
                }
                game_state->Players[id_player].penguins = penguinsArray;
                game_state->Board[x][y].idPenguin = *current_penguin;
                penguinsArray[*current_penguin].x = x;
                penguinsArray[*current_penguin].y = y;
                (*current_penguin)++;
            }
        }
    }
}
