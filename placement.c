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
    for (int i = 0; i < gameState->x_Board_size; i++)
    {
        for (int j = 0; j < gameState->y_Board_size; j++)
        {
            if (gameState->Board[i][j].amount_of_fish == 1)
            {
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
    for (int i = 0; i < gameState->num_of_players; ++i)
    {
        if (gameState->Players[i].current_penguin != gameState->num_of_penguins_per_player)
        {
            return false;
        }
    }
    return true;
}

bool isPlacementValid(struct GameState* gameState)
{
    printf("Checking whether the placement is valid or not.\n");
    int x = gameState->Players[gameState->current_player].x;
    int y = gameState->Players[gameState->current_player].y;
    //printf("%d %d \n",x,y);
    if (x<0 || y<0) {
        return false;
    }
    //printf("%d \n",gameState->Board[x][y].amount_of_fish == 1);
    if(gameState->Board[x][y].amount_of_fish == 1) {
        gameState->Players[gameState->current_player].penguins->y = y;
        gameState->Players[gameState->current_player].penguins->x = x;
        return true;
    }
    else return false;
}

void placePenguin(struct GameState* gameState)
{
    printf("Player %d 's penguin has been placed.\n", gameState->current_player + 1);
    change_penguin_position(gameState);
}
