//
// Created by theVo on 19/11/2025.
//

#include "playerActions.h"


void collectFish(struct GameState *gameState) {
    printf("Player %d has collected fish.\n", gameState->current_player + 1);
}

void changeCurrentPlayer(struct GameState *gameState) {
    gameState->current_player = (gameState->current_player + 1) % gameState->num_of_players;
    printf("Current player is player %d.\n", 1+gameState->current_player);
}

void askCoordinates(struct GameState *gameState) {
    int x,y;
    printf("Player %d, please input coordinates (row, column): \n",1+gameState->current_player);
    while (scanf("%s %s",x, y) != 2 || !isMoveValid()) {
        printf("Please provide correct values!\n");
        while (getchar() != '\n');

    }
}

bool isMoveValid()
{
    int chance = rand() % 5;
    return chance >= 1;
}
