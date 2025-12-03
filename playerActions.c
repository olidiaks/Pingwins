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
    char x[2], y[2];
    printf("Player %d, please input coordinates (row, column): \n", 1 + gameState->current_player);
    while (scanf("%s %s", &x, &y) != 2 || !isMoveValid(x, y, gameState)) {
        printf("Please provide correct values!\n");
        while (getchar() != '\n');
    }
}

bool isMoveValid(char x[2], char y[2], struct GameState *gameState) {

    printf("%s %s \n",x,y);
    
    char x_FirstChar = toupper(x[0]);
    char x_SecondChar = toupper(x[1]);
    char y_FirstChar = toupper(y[0]);
    char y_SecondChar = toupper(y[1]);

    printf("%c %c %c %c \n",x_FirstChar,x_SecondChar,y_FirstChar,y_SecondChar);

    int xo = (int) (x_FirstChar - 65) + (atoi(&x_SecondChar) - 1) * 26;
    int yo = (int) (y_FirstChar - 65) + (atoi(&y_SecondChar) - 1) * 26;

    printf("X: %d, Y: %d \n", xo, yo);

    return 0 < xo && xo < gameState->x_Board_size && 0 < yo && yo < gameState->y_Board_size;
}
