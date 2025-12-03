//
// Created by theVo on 19/11/2025.
//

#include "playerActions.h"

void collectFish(struct GameState *gameState) {
    printf("Player %d has collected fish.\n", gameState->current_player + 1);
}

void changeCurrentPlayer(struct GameState *gameState) {
    gameState->current_player = (gameState->current_player + 1) % gameState->num_of_players;
    printf("Current player is player %d.\n", 1 + gameState->current_player);
}

void askCoordinates(struct GameState *gameState) {
    char x[50], y[50];
    printf("Player %d, please input coordinates seperated with a space (row, column): \n", 1 + gameState->current_player);
    // while (scanf("%s %s", &x, &y) != 2 || !isMoveValid(x, y, gameState)) { // For now we assume that every movement is valid.
    while (scanf("%s %s", &x, &y) != 2) {
        printf("Please provide correct values!\n");
        while (getchar() != '\n');
    }
    char x_FirstChar = toupper(x[0]);
    char x_SecondChar = toupper(x[1]);
    char y_FirstChar = toupper(y[0]);
    char y_SecondChar = toupper(y[1]);
    int xo = (int) (x_FirstChar - 65) + (atoi(&x_SecondChar) - 1) * 26;
    int yo = (int) (y_FirstChar - 65) + (atoi(&y_SecondChar) - 1) * 26 - 260;

    gameState->Players[gameState->current_player].penguins->x = xo+1;
    gameState->Players[gameState->current_player].penguins->y = yo+1;
}

bool isMoveValid(char x, char y, struct GameState *gameState) {
    // make the function read xo and yo from the askCoordinates function
    return (0 > x) && (x > gameState->x_Board_size) && (0 > y) && (y > gameState->y_Board_size);
}
