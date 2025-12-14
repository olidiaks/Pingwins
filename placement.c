//
// Created by theVo on 19/11/2025.
//

#include "placement.h"

void placementPhase(struct GameState *gameState) {
    readBoardDimensions(gameState);
    generateBoard(gameState);
    while (canPlayerPlacePenguin(gameState)) {
        showBoard(gameState);
        askCoordinates(gameState);
        while (!isMoveValid(gameState)) {
            printf("Gaven coordinates are invalid");
            askCoordinates(gameState);
        }
        placePenguin(gameState);
        collectFish(gameState);
        canPlayerPlacePenguin(gameState);
        changeCurrentPlayer(gameState);
    }
}

bool canPlayerPlacePenguin(struct GameState *gameState) {
    int counter = 0;
    for (int i = 0; i < gameState->x_Board_size; i++) {
        for (int j = 0; j < gameState->y_Board_size; j++) {
            // printf("%d\n",gameState->Board[i][j].amount_of_fish);
            if (gameState->Board[i][j].amount_of_fish == 0) {
                counter++;
            }
        }
    }
    // printf("spots with 0 %d \n",counter);
    // printf("%d %d \n",gameState->x_Board_size,gameState->y_Board_size);
    if (counter == gameState->x_Board_size * gameState->y_Board_size || counter == gameState->num_of_players * gameState
        ->num_of_penguins_per_player) {
        return 0;
    } else {
        return 1;
    }
}

void placePenguin(struct GameState *gameState) {
    printf("Player %d 's penguin has been placed.\n", gameState->current_player + 1);
}

bool isEveryPenguinsPlaced(struct GameState *gameState) {
    int counter = 0;
    for (int i = 0; i < gameState->x_Board_size; i++) {
        for (int j = 0; j < gameState->y_Board_size; j++) {
            if (gameState->Board[i][j].amount_of_fish == 0) {
                counter++;
            }
        }
    }

    // printf("spots with 0 %d \n",counter);

    if (counter == 2) {
        return 1;
    } else if (!(canPlayerPlacePenguin(gameState))) {
        return 0;
    }
}
