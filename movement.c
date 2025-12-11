//
// Created by theVo on 19/11/2025.
//

#include "movement.h"

void movementPhase(struct GameState* gameState)
{
    while (isThereAnyPenguinMoveAvailable(gameState))
    {
        bool hasCurrentPlayerMoved = false;
        while (isPlayerMoveAvailable() && !(hasCurrentPlayerMoved))
        {
            showBoard(gameState);
            askCoordinates(gameState);
            while (!isMoveValid(gameState))
            {
                printf("Gaven coordinates are invalid!\n");
                askCoordinates(gameState);
            }
            movePenguin(gameState);
            collectFish(gameState);
            hasCurrentPlayerMoved = true;
        }
        changeCurrentPlayer(gameState);
    }
}

bool isThereAnyPenguinMoveAvailable(struct GameState* gameState)
{
    int counter = 0;
    for (int i = 0; i < gameState->x_Board_size; i++)
    {
        for (int j = 0; j < gameState->y_Board_size; j++)
        {
            if (gameState->Board[i][j].amount_of_fish == 0)
            {
                counter++;
            }
        }
    }
    if (counter == gameState->x_Board_size * gameState->y_Board_size)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

bool isPlayerMoveAvailable()
{
    // if the current player's penguin is surrounded from every direction by 0 (where 0 can also mean that 
    //there's another player's penguin standing on that spot) that player cannot move
    return 1;
}

void movePenguin(struct GameState* gameState)
{
    printf("Player %d's penguin has been moved.\n", gameState->current_player + 1);
}
