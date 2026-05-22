//
// Created by theVo on 19/11/2025.
//

#include "boardGeneration.h"

#include "movementInteractive.h"


void readBoardDimensions(struct GameState *gameState) {
    printf("Input dimensions of the board of which you want to play (number of rows then number of columns): \n");
    gameState->xBoardSize = (int)safe_number_read();
    gameState->yBoardSize = (int)safe_number_read();
    while (!isBoardDimensionsValid(gameState)) {
        printf("You need to give real numbers!\n");
        gameState->xBoardSize = (int)safe_number_read();
        gameState->yBoardSize = (int)safe_number_read();
    };
}

bool isBoardDimensionsValid(struct GameState *gameState) {
    if (gameState->xBoardSize <= 0 || gameState->yBoardSize <= 0) {
        printf("Board dimensions are invalid!\n"
            "Width and size need to be positive!\n");
    }
    return gameState->xBoardSize > 0 && gameState->yBoardSize > 0;
}

void generateFish(struct GameState *gameState, int x, int y) {
    const int ceil = 100;
    int randNum = rand() % ceil;
    const int chanceFor3Fish = 10;
    const int chanceFor2Fish = 30;
    const int chanceFor1Fish = ceil;

    if (randNum < chanceFor3Fish) {
        gameState->Board[x][y].amountOfFish = 3;
    } else if (randNum < chanceFor2Fish) {
        gameState->Board[x][y].amountOfFish = 2;
    } else if (randNum < chanceFor1Fish) {
        gameState->Board[x][y].amountOfFish = 1;
        gameState->numbOfTilesWithOneFish ++;
    }
}

void generateBoard(struct GameState *gameState) {
    printf("Generating random board...\n");
    gameState->numbOfTilesWithOneFish = 0;

    gameState->Board = malloc(gameState->xBoardSize * sizeof(struct Field));

    if (gameState->Board != NULL) {
        for (int x = 0; x < gameState->xBoardSize; x++) {
            gameState->Board[x] = malloc(gameState->yBoardSize * sizeof(struct Field));

            if (gameState->Board[x] != NULL) {
                for (int y = 0; y < gameState->yBoardSize; y++) {
                    gameState->Board[x][y].idPlayer = -1;
                    gameState->Board[x][y].idPenguin = -1;
                    generateFish(gameState, x, y);
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

    const int penguinsInGame = gameState->numOfPenguinsPerPlayer * gameState->numOfPlayers;
    for (int attept = 0; attept < 10 && gameState->numbOfTilesWithOneFish < penguinsInGame; attept++) {
        gameState->numbOfTilesWithOneFish = 0;
        for (int x = 0; x < gameState->xBoardSize; x++) {
            for (int y = 0; y < gameState->yBoardSize; y++) {
                generateFish(gameState, x, y);
            }
        }
    }

    int y_began = 0;
    while (gameState->numbOfTilesWithOneFish < penguinsInGame) {
        y_began = (y_began + 1) % 2;
        for (int x = 0; x < gameState->xBoardSize; x++) {
            for (int y = (y_began + x) % 2; y < gameState->yBoardSize; y += 2) {
                if (gameState->Board[x][y].amountOfFish != 1) {
                    gameState->Board[x][y].amountOfFish = 1;
                    gameState->numbOfTilesWithOneFish ++;
                }
            }
        }
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