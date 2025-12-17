//
// Created by theVo on 19/11/2025.
//

#include "placementInteractive.h"


void placementInteractiveMode(struct GameState *gameState) {
    readBoardDimensions(gameState);
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
            if (gameState->Board[i][j].amountOfFish == 1) {
                printf("FOUND COORDS: %d, %d", i, j);
                return true;
            }
        }
    }
    return false;
}


bool isEveryPenguinsPlaced(struct GameState* gameState)
{
    //TO DO: Verify if this actually make sense?
    //Note from Bryce: Please learn how to spell things correctly I am so tired of fixing your mistakes
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
