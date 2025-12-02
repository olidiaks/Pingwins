//
// Created by theVo on 19/11/2025.

#include "consoleVisualization.h"


void showBoard(struct GameState *gameState) {
    printf("Displaying the board.\n");
    for (int x = 0; x < gameState->x_Board_size; x++) {
        for (int y = 0; y < gameState->y_Board_size; y++) {
            printf("%d ", gameState->Board[x][y].amount_of_fish);
        }
        printf("\n");
    }
}
