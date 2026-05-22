//
// Created by theVo on 19/11/2025.
//

#include "movementInteractive.h"

#include <errno.h>

void movementPhaseInteractiveMode(struct GameState *gameState) {
    printf("- - - - - - - - - - \nCommencing movement phase. \n- - - - - - - - - -\n");
    int players_failed_to_move_in_row = 0;
    while (players_failed_to_move_in_row < gameState->numOfPlayers) {
        if (isPlayerAbleToMoveAnyPenguin(gameState)) {
            showBoard(gameState);
            printGameInfoMovement(gameState);
            askWhichPenguinMove(gameState);
            askCoordinates(gameState);
            while (!isCoordinateValid(gameState) || !isMoveValid(gameState)) {
                printf("Given coordinates are invalid!\n");
                askCoordinates(gameState);
            }
            movePenguin(gameState);
            collectFish(gameState);
            players_failed_to_move_in_row = 0;
        }
        else {
            printf("Player %d cannot move any penguin.\n", gameState->currentPlayer + 1);
            players_failed_to_move_in_row++;
        }
        changeCurrentPlayer(gameState);
    }
}

bool isPlayerAbleToMoveAnyPenguin(struct GameState *gameState) {
    for (int i = 0; i < gameState->numOfPenguinsPerPlayer; ++i) {
        int x = gameState->Players[gameState->currentPlayer].penguins[i].x;
        int y = gameState->Players[gameState->currentPlayer].penguins[i].y;

         if (checkAdjacentFishAvailability(gameState, x, y)) return true;
    }
    return  false;
}

void movePenguin(struct GameState *gameState) {
    removePenguinFromCurrentLocation(gameState);
    changePenguinPosition(gameState);
    collectFish(gameState);
    int currentPlayer = gameState->currentPlayer;
    int currentPenguin = gameState->Players[currentPlayer].currentPenguin;
    printf("Player %d's %d penguin has been moved.\n", currentPlayer + 1, currentPenguin + 1);
}

long int safe_number_read() {

    char *buffer_inp = NULL;
    char *buffer_conv = NULL;
    size_t len = 0;

    safe_read:
    getline(&buffer_inp, &len, stdin);
    errno = 0;
    long int id = strtol(buffer_inp, &buffer_conv, 10);

    if (buffer_conv == buffer_inp) {
        printf("Incorrect input is given.\nGave number once again.\n");
        free(buffer_inp);
        buffer_inp = NULL;
        buffer_conv = NULL;
        goto safe_read;
    }
    if (errno == ERANGE && (id == LONG_MAX || id == LONG_MIN)) {
        printf("Number given in is incorrect number.\nGave number once again.\n");
        free(buffer_inp);
        buffer_inp = NULL;
        buffer_conv = NULL;
        goto safe_read;
    }

    if (!(*buffer_conv == '\n' || *buffer_conv == '\0')) {
        printf("You provided number and somthing after that.\nGave number once again.\n");
        free(buffer_inp);
        buffer_inp = NULL;
        buffer_conv = NULL;
        goto safe_read;
    }
    free(buffer_inp);
    return id;
}
void askWhichPenguinMove(struct GameState *gameState) {
    printf("Which penguin (from 1 to %d) do you want to move?\n", gameState->numOfPenguinsPerPlayer);
    while ((getchar()) != '\n');
    long int id = 0;

    read_id:
    id = safe_number_read();
    id--;
    if (0 > id || id >= gameState->numOfPenguinsPerPlayer) {
        printf("The number of penguin provided is incorrect. Please try again. \n");
        goto read_id;
    }
    if (!isAnyMoveForCurrentPenguinAvailable(gameState)) {
        printf("There is no move available for the penguin you chosen. Try different one. \n");
        goto read_id;
    }
    gameState->Players[gameState->currentPlayer].currentPenguin = (int)id;
}

bool checkAdjacentFishAvailability(struct GameState *gameState, int x, int y) {
    return (0 < x && gameState->Board[x - 1][y].amountOfFish) || // check if one to the left has any fish
           (0 < y && gameState->Board[x][y - 1].amountOfFish) || // check if one to the top has any fish
           (x < (gameState->xBoardSize - 1) && gameState->Board[x + 1][y].amountOfFish) ||
           // check if one to the bottom has any fish
           (y < (gameState->yBoardSize - 1) && gameState->Board[x][y + 1].amountOfFish);
    // check if one to the right has any fish
}

bool isAnyMoveForCurrentPenguinAvailable(struct GameState *gameState) {
    int current_player = gameState->currentPlayer;
    int currnet_penguin = gameState->Players[current_player].currentPenguin;
    int x = gameState->Players[current_player].penguins[currnet_penguin].x;
    int y = gameState->Players[current_player].penguins[currnet_penguin].y;
    return checkAdjacentFishAvailability(gameState, x, y);
}

void removePenguinFromCurrentLocation(struct GameState *gameState) {
    int currentPlayer = gameState->currentPlayer;
    int currentPenguin = gameState->Players[currentPlayer].currentPenguin;
    int x = gameState->Players[currentPlayer].penguins[currentPenguin].x;
    int y = gameState->Players[currentPlayer].penguins[currentPenguin].y;
    gameState->Board[x][y].idPlayer = -1;
    gameState->Board[x][y].idPenguin = -1;
}
