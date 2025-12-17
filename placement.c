//
// Created by theVo on 19/11/2025.
//

#include "placement.h"


void placementPhase(struct GameState* gameState)
{
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
    printf("Checking whether the placement is valid or not.\n");
    int x = gameState->Players[gameState->currentPlayer].x;
    int y = gameState->Players[gameState->currentPlayer].y;
    //printf("%d %d \n",x,y);
    if (x <0 || y<0) {
        return false;
    }
    //printf("%d \n",gameState->Board[x][y].amountOfFish == 1);
    if (gameState->Board[x][y].amountOfFish == 1) {
        gameState->Players[gameState->currentPlayer].penguins->y = y;
        gameState->Players[gameState->currentPlayer].penguins->x = x;
        return true;
    } else return false;
}

void placePenguin(struct GameState* gameState)
{
    printf("Player %d 's penguin has been placed.\n", gameState->currentPlayer + 1);
    changePenguinPosition(gameState);
}
