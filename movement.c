//
// Created by theVo on 19/11/2025.
//

#include "movement.h"

void movementPhase(struct GameState* gameState)
{
    while (isThereAnyPenguinMoveAvailable(gameState))
    {
        while (isPlayerAbleToMobeAnyPenguin(gameState))
        {
            showBoard(gameState);
            askWhichPenguinMove(gameState);
            askCoordinates(gameState);
            while (!isCoordinateValid(gameState))
            {
                printf("Given coordinates are invalid!\n");
                askCoordinates(gameState);
            }
            movePenguin(gameState);
            collectFish(gameState);
            changeCurrentPlayer(gameState);
        }
    }
}

bool check_adjacent_fish_availability(struct GameState* gameState, int x, int y)
{
    return (0 < x && gameState->Board[x - 1][y].amount_of_fish) || //check if one to the left has any fish
        (0 < y && gameState->Board[x][y - 1].amount_of_fish) || // check if one to the top has any fish
        (x < gameState->x_Board_size && gameState->Board[x + 1][y].amount_of_fish) ||
        // check if one to the bottom has any fish
        (y < gameState->y_Board_size && gameState->Board[x][y + 1].amount_of_fish);
    // check if one to the right has any fish
}

bool isThereAnyPenguinMoveAvailable(struct GameState* gameState)
{
    for (int i = 0; i < gameState->num_of_players; i++)
    {
        for (int j = 0; j < gameState->num_of_penguins_per_player; j++)
        {
            int x = gameState->Players[i].penguins[j].x;
            int y = gameState->Players[i].penguins[j].y;

            return check_adjacent_fish_availability(gameState, x, y);
        }
    }
}

bool isPlayerAbleToMobeAnyPenguin(struct GameState* gameState)
{
    for (int i = 0; i < gameState->num_of_penguins_per_player; ++i)
    {
        int x = gameState->Players[gameState->current_player].penguins[i].x;
        int y = gameState->Players[gameState->current_player].penguins[i].y;

        return check_adjacent_fish_availability(gameState, x, y);
    }
}

void movePenguin(struct GameState* gameState)
{
    printf("Player %d's penguin has been moved.\n", gameState->current_player + 1);
    change_penguin_position(gameState);
}

void askWhichPenguinMove(struct GameState* gameState)
{
    printf("Which pengiun(0 – %d) do you want to move?\n", gameState->num_of_penguins_per_player - 1);
    int id;
    while (scanf("%d", &id) && 0 <= id && id < gameState->num_of_penguins_per_player)
    {
        gameState->Players[gameState->current_player].current_penguin = id;
    }
}
