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

        int xOffset = toupper(x[0]);
        int xDirect = toupper(x[1]);
        int yOffset = toupper(y[0]);
        int yDirect = toupper(y[1]);

        int xFinal = xOffset - 64 + (xDirect - 49) * 26;
        int yFinal = yOffset - 64 + (yDirect - 49) * 26;

        printf("%c %d\n", xDirect, *&xDirect);

        printf("xFinal: %d, yFinal: %d\n", xFinal, yFinal);

        gameState->Players[gameState->current_player].x = xFinal;
        gameState->Players[gameState->current_player].y = yFinal;
    }

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
