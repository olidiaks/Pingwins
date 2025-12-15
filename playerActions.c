//
// Created by theVo on 19/11/2025.
//

#include "playerActions.h"

void collectFish(struct GameState *gameState) {
    int x = gameState->Players[gameState->current_player].x;
    int y = gameState->Players[gameState->current_player].y;
    gameState->Players[gameState->current_player].current_score += gameState->Board[x][y].amount_of_fish;
    gameState->Board[x][y].amount_of_fish = 0;
    printf("Player %d has collected fish.\n", gameState->current_player + 1);
}

void changeCurrentPlayer(struct GameState *gameState) {
    gameState->current_player = (gameState->current_player + 1) % gameState->num_of_players;
    printf("Current player is player %d.\n", 1 + gameState->current_player);
}

void askCoordinates(struct GameState *gameState) {
    char *x = NULL; 
    char *y = NULL;

    unsigned short lenX;
    unsigned short lenY;

    if (scanf("%ms %ms", &x, &y) == 2) {

        lenX = strlen(x);
        lenY = strlen(y);
    }

    if (lenX == 2 && lenY == 2) {

        char xOffset = toupper(x[0]);
        char xDirect = toupper(x[1]);
        char yOffset = toupper(y[0]);
        char yDirect = toupper(y[1]);

        int xFinal = atoi(&xDirect) + (xOffset - 65) * 26;
        int yFinal = atoi(&yDirect) + (yOffset - 65) * 26;
        
        printf("%d, %d\n", atoi(&xDirect), (xOffset - 65));
        printf("xFinal: %d, yFinal: %d\n", xFinal, yFinal);

        gameState->Players[gameState->current_player].x = xFinal;
        gameState->Players[gameState->current_player].y = yFinal;
    }

    /*
    printf("Player %d, please input coordinates seperated with a space (row, column): \n",
           1 + gameState->current_player);
    // while (scanf("%s %s", &x, &y) != 2 || !isCoordinateValid(x, y, gameState)) { // For now we assume that every movement is valid.
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
    */

    //gameState->Players[gameState->current_player].x = x; //temp change
    //gameState->Players[gameState->current_player].y = y; //temp change
}

bool isCoordinateValid(struct GameState *gameState) {
    // make the function read xo and yo from the askCoordinates function
    int x = gameState->Players[gameState->current_player].x;
    int y = gameState->Players[gameState->current_player].y;
    return (0 <= x) && (x < gameState->x_Board_size) && (0 <= y) && (y < gameState->y_Board_size);
}

void change_penguin_position(struct GameState *gameState) {
    int x = gameState->Players[gameState->current_player].x;
    gameState->Players[gameState->current_player].penguins[gameState->Players[gameState->current_player].
        current_penguin].x = x;
    int y = gameState->Players[gameState->current_player].y;
    gameState->Players[gameState->current_player].penguins[gameState->Players[gameState->current_player].
        current_penguin].y = y;

    gameState->Board[x][y].id_player = gameState->current_player;
    gameState->Board[x][y].id_penguin = gameState->Players[gameState->current_player].current_penguin;
}

void changeCurrentPenguin(struct GameState *gameState) {
    gameState->Players[gameState->current_player].current_penguin++;
}
