//
// Created by theVo on 19/11/2025.
//

#include "boardGeneration.h"

#include <stdlib.h>

void readBoardDimensions() {
    printf("Reading board dimensions...\n");
}

void generateRandomBoard() {
    printf("Generating random board...\n");
    for (int x = 0; x < gameState.x_Board_size; x++) {
        for (int y = 0; y < gameState.y_Board_size; y++) {
            gameState.Board[x][y].amount_of_fish = rand() % 10;
            gameState.Board[x][y].id_player = -1;
        }
    }
}
