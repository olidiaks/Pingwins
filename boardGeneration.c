//
// Created by theVo on 19/11/2025.
//

#include "boardGeneration.h"


void readBoardDimensions(struct GameState *gameState) {
    printf("Input dimensions of the board of which you want to play (number of rows then number of columns): \n");
    while (scanf("%d %d", &gameState->y_Board_size, &gameState->x_Board_size) != 2 || !
           isBoardDimensionsValid(gameState)) {
        printf("You need to give real numbers!\n");
        while (getchar() != '\n');
    };
}

bool isBoardDimensionsValid(struct GameState *gameState) {
    if (gameState->x_Board_size <= 0 || gameState->y_Board_size <= 0) {
        printf("Board dimensions are invalid!\n"
            "Width and size need to be positive!\n");
    }
    return gameState->x_Board_size > 0 && gameState->y_Board_size > 0;
}

void generateRandomBoard(struct GameState *gameState) {
    printf("Generating random board...\n");
    gameState->Board = malloc(gameState->x_Board_size * sizeof(struct Field *));
    for (int x = 0; x < gameState->x_Board_size; x++) {
        gameState->Board[x] = malloc(gameState->y_Board_size * sizeof(struct Field));
        for (int y = 0; y < gameState->y_Board_size; y++) {
            //gameState->Board[x][y].amount_of_fish = (rand() % 3)+1;
            //gameState->Board[x][y].id_player = -1;

            const int ceil = 100;
            int randNum = rand() % ceil;
            const int step3 = 10;
            const int step2 = 30;
            const int step1 = ceil;

            if (randNum < step3) {
                gameState->Board[x][y].amount_of_fish = 3;
            }
            else if (randNum < step2) {
                gameState->Board[x][y].amount_of_fish = 2;
            }
            else if (randNum < step1) {
                gameState->Board[x][y].amount_of_fish = 1;
            }
        }
    }
}
