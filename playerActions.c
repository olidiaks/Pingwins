//
// Created by theVo on 19/11/2025.
//

#include "playerActions.h"


void collectFish(struct GameState *gameState) {
    printf("Player %d has collected fish.\n", gameState->current_player + 1);
}

void changeCurrentPlayer(struct GameState *gameState) {
    gameState->current_player = (gameState->current_player + 1) % gameState->num_of_players;
    printf("Current player is player %d.\n", gameState->current_player);
}

void askCoordinates(struct GameState *gameState) {
    printf("Please input coordinates (row, column): \n");
    // while (scanf("%s %s", &gameState->y_Board_size, &gameState->x_Board_size) != 2 || !
    //        isBoardDimensionsValid(gameState));
}

bool isMoveValid()
{
    int chance = rand() % 5;
    return chance >= 1;
}
