//
// Created by theVo on 19/11/2025.
//

#include "movement.h"

void movementPhase(struct GameState *gameState) {
    while (isThereAnyPenguinMoveAvailable(gameState)) {
        while (isPlayerAbleToMoveAnyPenguin(gameState)) {
            showBoard(gameState);
            printGameInfoMovement(gameState);
            askWhichPenguinMove(gameState);
            askCoordinates(gameState);
            while (!(isCoordinateValid(gameState) && isMoveValid(gameState))) {
                printf("Given coordinates are invalid!\n");
                askCoordinates(gameState);
            }
            movePenguin(gameState);
            collectFish(gameState);
            changeCurrentPlayer(gameState);
        }
    }
}

bool checkAdjacentFishAvailability(struct GameState *gameState, int x, int y) {
    return (0 < x && gameState->Board[x - 1][y].amountOfFish) || //check if one to the left has any fish
           (0 < y && gameState->Board[x][y - 1].amountOfFish) || // check if one to the top has any fish
           (x < gameState->xBoardSize && gameState->Board[x + 1][y].amountOfFish) ||
           // check if one to the bottom has any fish
           (y < gameState->yBoardSize && gameState->Board[x][y + 1].amountOfFish);
    // check if one to the right has any fish
}

bool isAnyMoveForCurrentPenguinAvailable(struct GameState *gameState) {
    int current_player = gameState->currentPlayer;
    int currnet_penguin = gameState->Players[current_player].currentPenguin;
    int x = gameState->Players[current_player].penguins[currnet_penguin].x;
    int y = gameState->Players[current_player].penguins[currnet_penguin].y;
    return checkAdjacentFishAvailability(gameState, x, y);
}

bool isThereAnyPenguinMoveAvailable(struct GameState *gameState) {
    for (int i = 0; i < gameState->numOfPlayers; i++) {
        for (int j = 0; j < gameState->numOfPenguinsPerPlayer; j++) {
            int x = gameState->Players[i].penguins[j].x;
            int y = gameState->Players[i].penguins[j].y;

            return checkAdjacentFishAvailability(gameState, x, y);
        }
    }
}

bool isPlayerAbleToMoveAnyPenguin(struct GameState *gameState) {
    for (int i = 0; i < gameState->numOfPenguinsPerPlayer; ++i) {
        int x = gameState->Players[gameState->currentPlayer].penguins[i].x;
        int y = gameState->Players[gameState->currentPlayer].penguins[i].y;

        return checkAdjacentFishAvailability(gameState, x, y);
    }
}

void movePenguin(struct GameState *gameState) {
    printf("Player %d's penguin has been moved.\n", gameState->currentPlayer + 1);
    changePenguinPosition(gameState);
}

void askWhichPenguinMove(struct GameState *gameState) {
    printf("Which penguin (from 1 to %d) do you want to move?\n", gameState->numOfPenguinsPerPlayer);
    int id;

read_id:
    scanf("%d", &id);
    id--;
    gameState->Players[gameState->currentPlayer].currentPenguin = id;
    if (0 > id || id >= gameState->numOfPenguinsPerPlayer) {
        printf("The number of penguin provided is incorrect. Please try again. \n");
        goto read_id;
    }
    if (!isAnyMoveForCurrentPenguinAvailable(gameState)) {
        printf("There is no move available for the penguin you chosen. Try different one. \n");
        goto read_id;
    }
}
