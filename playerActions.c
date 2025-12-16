//
// Created by theVo on 19/11/2025.
//

#include "playerActions.h"

void collectFish(struct GameState* gameState)
{
    int x = gameState->Players[gameState->current_player].x;
    int y = gameState->Players[gameState->current_player].y;
    gameState->Players[gameState->current_player].current_score += gameState->Board[x][y].amount_of_fish;
    gameState->Board[x][y].amount_of_fish = 0;
    printf("Player %d has collected fish.\n", gameState->current_player + 1);
}

void changeCurrentPlayer(struct GameState* gameState)
{
    gameState->current_player = (gameState->current_player + 1) % gameState->num_of_players;
    printf("Current player is player %d.\n", 1 + gameState->current_player);
}

void askCoordinates(struct GameState* gameState)
{
    printf("Gave coordinates for move separated by space.\n");

    char* x = NULL;
    char* y = NULL;

    unsigned short lenX;
    unsigned short lenY;

    if (scanf("%ms %ms", &x, &y) == 2)
    {
        lenX = strlen(x);
        lenY = strlen(y);
    }

    if (lenX == 2 && lenY == 2)
    {
        int xOffset = toupper(x[0]);
        int xDirect = toupper(x[1]);
        int yOffset = toupper(y[0]);
        int yDirect = toupper(y[1]);

        int xFinal = xOffset - 64 + (xDirect - 49) * 26;
        int yFinal = yOffset - 64 + (yDirect - 49) * 26;


        gameState->Players[gameState->current_player].x = xFinal - 1;
        gameState->Players[gameState->current_player].y = yFinal - 1;
    }
}

bool isCoordinateValid(struct GameState* gameState)
{
    // make the function read xo and yo from the askCoordinates function
    int x = gameState->Players[gameState->current_player].x;
    int y = gameState->Players[gameState->current_player].y;

    printf("CHECKING CORDS: X, Y: %d, %d\n", x, y);

    return (0 <= x) && (x < gameState->x_Board_size) && (0 <= y) && (y < gameState->y_Board_size);
}

bool isMoveValid(struct GameState* gameState)
{
    int curPlr = gameState->current_player;
    int moveX, moveY, curX, curY;

    curX = gameState->Players[curPlr].penguins[gameState->Players[curPlr].current_penguin].x;
    curY = gameState->Players[curPlr].penguins[gameState->Players[curPlr].current_penguin].y;

    moveX = gameState->Players[curPlr].x;
    moveY = gameState->Players[curPlr].y;

    int deltaX, deltaY, dt;
    
    deltaX = moveX - curX;
    deltaY = moveY - curY;

    if (deltaX * deltaY != 0) // Either one direction or another. If we move even a centimeter in both directions the delta for both will be non-zero
        return false;
    
    if (deltaX != 0) {

        int iterator = 0;
        int cPosX, cPosY = curX, curY;
        int sign = deltaX / abs(deltaX);

        if (iterator > deltaX) {
            iterator = deltaX;
            deltaX = 0;         //We perform this fantastic manouver to make sure for if goes lower -> bigger

            for (iterator; iterator <= deltaX; iterator++) {
                cPosX += sign;
                if (gameState->Board[cPosX][cPosY].amount_of_fish <= 0) {
                    printf("MOVE FALSE X!\n");
                    return false;
                }
            }

            return true;
        }
    }
    else
    {
        
        int iterator = 0;
        int cPosX, cPosY = curX, curY;
        int sign = deltaY / abs(deltaY);

        if (iterator > deltaY) {
            iterator = deltaY;
            deltaY = 0;         //We perform this fantastic manouver to make sure for if goes lower -> bigger

            for (iterator; iterator <= deltaY; iterator++) {
                cPosY += sign;
                if (gameState->Board[cPosX][cPosY].amount_of_fish <= 0) {
                    printf("MOVE FALSE Y!\n");
                    return false;
                }
            }

            return true;
        }
    }

}

void change_penguin_position(struct GameState* gameState)
{
    
    int curPlr = gameState->current_player;
    
    int x = gameState->Players[curPlr].x;
    gameState->Players[curPlr].penguins[gameState->Players[curPlr].current_penguin].x = x;

    int y = gameState->Players[curPlr].y;
    gameState->Players[curPlr].penguins[gameState->Players[curPlr].current_penguin].y = y;

    gameState->Board[x][y].id_player = curPlr;
    gameState->Board[x][y].id_penguin = gameState->Players[curPlr].current_penguin;
}

void changeCurrentPenguin(struct GameState* gameState)
{
    gameState->Players[gameState->current_player].current_penguin++;
}
