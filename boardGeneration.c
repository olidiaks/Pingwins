//
// Created by theVo on 19/11/2025.
//

#include "boardGeneration.h"


void readBoardDimensions() {
    printf("Give a size of filed on which you want to play: \n");
    while (scanf("%d %d", &gameState.x_Board_size, &gameState.y_Board_size) != 2 || !isBoardDimensionsValid()) {
        printf("You need to give real numbers!\n");
        while (getchar() != '\n');
    };
}

bool isBoardDimensionsValid() {
    if (gameState.x_Board_size <= 0 || gameState.y_Board_size <= 0) {
        printf("Board dimensions are invalid!\n"
            "Width and size need to be positive!\n");
    }
    return gameState.x_Board_size > 0 && gameState.y_Board_size > 0;
}

void generateRandomBoard() {
    printf("Generating random board...\n");
    gameState.Board = malloc(gameState.x_Board_size * sizeof(struct Field*));
    for (int x = 0; x < gameState.x_Board_size; x++) {
        gameState.Board[x] = malloc(gameState.y_Board_size * sizeof(struct Field));
        for (int y = 0; y < gameState.y_Board_size; y++) {
            gameState.Board[x][y].amount_of_fish = rand() % 10;
            gameState.Board[x][y].id_player = -1;
        }
    }
}
