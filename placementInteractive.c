//
// Created by theVo on 19/11/2025.
//

#include "placementInteractive.h"

void placementInteractiveMode(struct GameState *gameState) {
    readBoardDimensions(gameState);
    isBoardBigEnough(gameState);
    printf("- - - - - - - - - - \nCommencing placement phase. \n- - - - - - - - - -\n");
    generateBoard(gameState);
    while (canPlayerPlacePenguin(gameState) && !isEveryPenguinsPlaced(gameState))
    {
        showBoard(gameState);
        printGameInfo(gameState);
        askCoordinates(gameState);
        while (!(isCoordinateValid(gameState) && isPlacementValid(gameState))){
            printf("Given coordinates are invalid!\nPlease notice that you may only place a penguin on a tile with a singular fish.\n");
            askCoordinates(gameState);
        }
        placePenguin(gameState);
        collectFish(gameState);
        changeCurrentPenguin(gameState);
        changeCurrentPlayer(gameState);
    }
}

bool canPlayerPlacePenguin(struct GameState* gameState)
{
    for (int i = 0; i < gameState->xBoardSize; i++) {
        for (int j = 0; j < gameState->yBoardSize; j++) {
            int amount_of_fish = gameState->Board[i][j].amountOfFish;
            if (amount_of_fish == 1) {
                return true;
            }
        }
    }
    return false;
}


bool isEveryPenguinsPlaced(struct GameState* gameState)
{
    for (int i = 0; i < gameState->numOfPlayers; ++i) {
        if (gameState->Players[i].currentPenguin != gameState->numOfPenguinsPerPlayer) {
            return false;
        }
    }
    return true;
}

bool isPlacementValid(struct GameState* gameState)
{
    int x = gameState->Players[gameState->currentPlayer].x;
    int y = gameState->Players[gameState->currentPlayer].y;
    return gameState->Board[x][y].amountOfFish == 1;
}

void placePenguin(struct GameState* gameState)
{
    printf("Player %d 's penguin has been placed.\n", gameState->currentPlayer + 1);
    changePenguinPosition(gameState);
}

void isBoardBigEnough(struct GameState *gameState) {
    if (gameState->numOfPlayers * gameState->numOfPenguinsPerPlayer > gameState->xBoardSize * gameState->yBoardSize) {
        printf("Dimensions of filed provided are not big enough to place all penguins");
        exit(7);
    };
}