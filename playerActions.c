//
// Created by theVo on 19/11/2025.
//

#include "playerActions.h"

void collectFish(struct GameState *gameState) {
    int x = gameState->Players[gameState->current_player].penguins->x;
    int y = gameState->Players[gameState->current_player].penguins->y;
    gameState->Players[gameState->current_player].current_score += gameState->Board[x - 1][y - 1].amount_of_fish;
    gameState->Board[x - 1][y - 1].amount_of_fish = 0;
    printf("Player %d has collected fish.\n", gameState->current_player + 1);
}

void changeCurrentPlayer(struct GameState *gameState) {
    gameState->current_player = (gameState->current_player + 1) % gameState->num_of_players;
    printf("Current player is player %d.\n", 1 + gameState->current_player);
}

void askCoordinates(struct GameState *gameState) {
    int x, y;
    printf("Player %d, please input coordinates seperated with a space (row, column): \n",
           1 + gameState->current_player);
    // while (scanf("%s %s", &x, &y) != 2 || !isMoveValid(x, y, gameState)) { // For now we assume that every movement is valid.
    while (scanf("%d %d", &x, &y) != 2) {
        printf("Please provide correct values!\n");
        while (getchar() != '\n');
    }

    gameState->Players[gameState->current_player].penguins->x = x;
    gameState->Players[gameState->current_player].penguins->y = y;
}

bool isMoveValid(struct GameState *gameState) {
    // make the function read xo and yo from the askCoordinates function
    int x = gameState->Players[gameState->current_player].penguins->x;
    int y = gameState->Players[gameState->current_player].penguins->y;
    return (0 < x) && (x <= gameState->x_Board_size) && (0 < y) && (y <= gameState->y_Board_size);
}
