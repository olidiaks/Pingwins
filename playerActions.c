//
// Created by theVo on 19/11/2025.
//

#include "playerActions.h"

void collectFish(struct GameState *gameState) {
    int x = gameState->Players[gameState->currentPlayer].penguins->x;
    int y = gameState->Players[gameState->currentPlayer].penguins->y;
    printf("x = %d, y = %d \n", x, y);
    gameState->Players[gameState->currentPlayer].currentScore += gameState->Board[x][y].amountOfFish;
    gameState->Board[x][y].amountOfFish = 0;
    printf("Player %d has collected fish.\n", gameState->currentPlayer + 1);
}

void changeCurrentPlayer(struct GameState *gameState) {
    gameState->currentPlayer = (gameState->currentPlayer + 1) % gameState->numOfPlayers;
    printf("Current player is player %d.\n", 1 + gameState->currentPlayer);
}

void askCoordinates(struct GameState *gameState) {
    printf("Please input coordinates (row column): \n");

    char *x = NULL;
    char *y = NULL;

    unsigned short lenX = 0;
    unsigned short lenY = 0;

    if (scanf("%ms %ms", &x, &y) == 2 && strlen(x) == 2 && strlen(y) == 2) {
        int xOffset = toupper(x[0]);
        int xDirect = toupper(x[1]);
        int yOffset = toupper(y[0]);
        int yDirect = toupper(y[1]);

        int xFinal = xOffset - 64 + (xDirect - 49) * 26;
        int yFinal = yOffset - 64 + (yDirect - 49) * 26;


        gameState->Players[gameState->currentPlayer].x = xFinal - 1;
        gameState->Players[gameState->currentPlayer].y = yFinal - 1;
    } else {
        printf("Check once again how cordinates of that field are called.\n");

        gameState->Players[gameState->currentPlayer].x = -1;
        gameState->Players[gameState->currentPlayer].y = -1;
    }
}

bool isCoordinateValid(struct GameState *gameState) {
    int x = gameState->Players[gameState->currentPlayer].x;
    int y = gameState->Players[gameState->currentPlayer].y;

    printf("CHECKING COORDINATES: X = %d, Y = %d\n", x, y);

    return ((0 <= x) && (x < gameState->xBoardSize) && (0 <= y) && (y < gameState->yBoardSize));
}

void swapSmallerBiggerNumbers(int *x, int *y) {
    if (*x > *y) {
        int temp = *x;
        *x = *y;
        *y = temp;
    }
}

bool isMoveValid(struct GameState *gameState) {
    //TODO: Delete hot fix, and do it correctly Wojtek.

    int curPlr = gameState->currentPlayer;
    int moveX, moveY, curX, curY;

    curX = gameState->Players[curPlr].penguins[gameState->Players[curPlr].currentPenguin].x;
    curY = gameState->Players[curPlr].penguins[gameState->Players[curPlr].currentPenguin].y;

    moveX = gameState->Players[curPlr].x;
    moveY = gameState->Players[curPlr].y;


    //TODO: Delete hot fix, and do it correctly Wojtek.

    if (curX != moveX && curY != moveY) {
        printf("Invalid move! Move only horizontally or vertically.\n");
        return false;
    }

    if (curX == moveX) {
        swapSmallerBiggerNumbers(&moveY, &curY);
        for (int y = moveY; y < curY; y++) {
            if (gameState->Board[moveX][y].amountOfFish == 0) {
                printf(
                    "Invalid move! You can only slide in straight lines to a tile with fish. Make sure your path is clear.\n");
                return false;
            }
        }
    }

    if (curY == moveY) {
        swapSmallerBiggerNumbers(&moveX, &curX);
        for (int x = moveX; x < curX; x++) {
            if (gameState->Board[x][moveY].amountOfFish == 0) {
                printf(
                    "Invalid move! You can only slide in straight lines to a tile with fish. Make sure your path is clear.\n");
                return false;
            }
        }
    }

    return true;


    //End fo HotFix.

    printf("cur X = %d cur Y = %d move X = %d move Y = %d\n", curX, curY, moveX, moveY);

    int deltaX, deltaY, dt;

    deltaX = abs(moveX - curX);
    deltaY = abs(moveY - curY);

    printf("delta x = %d delta y = %d\n", deltaX, deltaY);
    printf("%d \n", gameState->Board[moveY, moveX]->amountOfFish);

    if (gameState->Board[moveY, moveX]->amountOfFish == 0) {
        printf("Player didn't move penguin to a hole/another penguin\n");
        return false;
    }


    if (deltaX * deltaY != 0) {
        // Either one direction or another. If we move even a centimeter in both directions the delta for both will be non-zero
        printf("You're trying to move the penguin in an illegal way.\n");
        return false;
    }

    printf("Player didn't input an invalid move\n");

    if (deltaX != 0) {
        int iterator = 0;
        int cPosX, cPosY = curX, curY;
        int sign = deltaX / abs(deltaX);

        if (iterator > deltaX) {
            iterator = deltaX;
            deltaX = 0; //We perform this fantastic manouver to make sure for if goes lower -> bigger

            for (iterator; iterator <= deltaX; iterator++) {
                cPosX += sign;
                if (gameState->Board[cPosX][cPosY].amountOfFish <= 0) {
                    printf("MOVE INCORRECT (ROW)!\n");
                    return false;
                }
            }

            return true;
        }
    } else {
        int iterator = 0;
        int cPosX, cPosY = curX, curY;
        int sign = deltaY / abs(deltaY);

        if (iterator > deltaY) {
            iterator = deltaY;
            deltaY = 0; //We perform this fantastic manouver to make sure for if goes lower -> bigger

            for (iterator; iterator <= deltaY; iterator++) {
                cPosY += sign;
                if (gameState->Board[cPosX][cPosY].amountOfFish <= 0) {
                    printf("MOVE INCORRECT (COLUMN)!\n");
                    return false;
                }
            }

            return true;
        }
    }
}

void changePenguinPosition(struct GameState *gameState) {
    int curPlr = gameState->currentPlayer;

    int x = gameState->Players[curPlr].x;
    gameState->Players[curPlr].penguins[gameState->Players[curPlr].currentPenguin].x = x;

    int y = gameState->Players[curPlr].y;
    gameState->Players[curPlr].penguins[gameState->Players[curPlr].currentPenguin].y = y;

    gameState->Board[x][y].idPlayer = curPlr;
    gameState->Board[x][y].idPenguin = gameState->Players[curPlr].currentPenguin;
}

void changeCurrentPenguin(struct GameState *gameState) {
    gameState->Players[gameState->currentPlayer].currentPenguin++;
}
