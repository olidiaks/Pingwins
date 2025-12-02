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
    char x[2],y[2];
    printf("Player %d, please input coordinates (row, column): \n",1+gameState->current_player);
    while (scanf("%s %s",x, y) != 2 || !isMoveValid(x, y)) {
        printf("Please provide correct values!\n");
        while (getchar() != '\n');

    }
}

bool isMoveValid(char x[2], char y[2])
{

    char x_FirstChar = toupper(x[0]);
    char x_SecondChar = toupper(x[1]);
    char y_FirstChar = toupper(y[0]);
    char y_SecondChar = toupper(y[1]);

    int x_value = x_FirstChar - '0' + atoi(x_SecondChar) * 26;
    int y_value = y_FirstChar - '0' + atoi(y_SecondChar) * 26;

    printf("X: %d, Y: %d", x_value, y_value);


    return true;
}
