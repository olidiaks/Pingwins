//
// Created by theVo on 19/11/2025.
//

#include "boardGeneration.h"


void readBoardDimensions(struct GameState *gameState) {
    printf("Input dimensions of the board of which you want to play (number of rows then number of columns): \n");
    while (scanf("%d %d", &gameState->xBoardSize, &gameState->yBoardSize) != 2 || !
           isBoardDimensionsValid(gameState)) {
        printf("You need to give real numbers!\n");
        while (getchar() != '\n');
    };
}

bool isBoardDimensionsValid(struct GameState *gameState) {
    if (gameState->xBoardSize <= 0 || gameState->yBoardSize <= 0) {
        printf("Board dimensions are invalid!\n"
            "Width and size need to be positive!\n");
    }
    return gameState->xBoardSize > 0 && gameState->yBoardSize > 0;
}

void generateBoard(struct GameState *gameState) {
    printf("Generating random board...\n");
    gameState->Board = malloc(gameState->xBoardSize * sizeof(struct Field));

    if (gameState->Board != NULL) {
        for (int x = 0; x < gameState->xBoardSize; x++) {
            gameState->Board[x] = malloc(gameState->yBoardSize * sizeof(struct Field));

            if (gameState->Board[x] != NULL) {
                for (int y = 0; y < gameState->yBoardSize; y++) {
                    gameState->Board[x][y].idPlayer = -1;
                    gameState->Board[x][y].idPenguin = -1;

                    const int ceil = 100;
                    int randNum = rand() % ceil;
                    const int step3 = 10;
                    const int step2 = 30;
                    const int step1 = ceil;

                    if (randNum < step3) {
                        gameState->Board[x][y].amountOfFish = 3;
                    } else if (randNum < step2) {
                        gameState->Board[x][y].amountOfFish = 2;
                    } else if (randNum < step1) {
                        gameState->Board[x][y].amountOfFish = 1;
                    }
                }
            } else {
                fprintf(stderr, "Error: Failed to allocate memory for board row %d.\n", x);

                exit(2);
            }
        }
    } else {
        fprintf(stderr, "Error: Failed to allocate memory for board structure.\n");
        exit(2);
    }
}

void generateVoidBoard(struct GameState *gameState) {
    printf("Generating new void board...\n");


    gameState->Board = malloc(gameState->xBoardSize * sizeof(struct Field));
    if (gameState->Board != NULL) {
        for (int x = 0; x < gameState->xBoardSize; x++) {
            gameState->Board[x] = malloc(gameState->yBoardSize * sizeof(struct Field));

            if (gameState->Board[x] != NULL) {
                for (int y = 0; y < gameState->yBoardSize; y++) {

                    gameState->Board[x][y].idPlayer = -1;
                    gameState->Board[x][y].idPenguin = -1;
                    gameState->Board[x][y].amountOfFish = 0;
                }
            } else {
                fprintf(stderr, "Error: Failed to allocate memory for board row %d.\n", x);

                exit(2);
            }
        }
    } else {
        fprintf(stderr, "Error: Failed to allocate memory for board structure.\n");
        exit(2);
    }
}