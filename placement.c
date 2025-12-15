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
        while (!isCoordinateValid(gameState) && !isPlacemntVaild(gameState)) {
            printf(
                "Given coordinates are invalid!\nAlso notice that penguin can be only placed on filed where is only one fish.\n");
            askCoordinates(gameState);
        }
        placePenguin(gameState);
        collectFish(gameState);
        changeCurrentPenguin(gameState);
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
    return counter != gameState->x_Board_size * gameState->y_Board_size && counter != gameState->num_of_players *
           gameState->num_of_penguins_per_player;
}


bool isEveryPenguinsPlaced(struct GameState *gameState) {
    for (int i = 0; i < gameState->num_of_players; ++i) {
        if (gameState->Players[i].current_penguin != gameState->num_of_penguins_per_player) {
            return false;
        }
    }
    return true;
}

bool isPlacemntVaild(struct GameState *gameState) {
    int x = gameState->Players[gameState->current_player].penguins->x;
    int y = gameState->Players[gameState->current_player].penguins->y;
    return gameState->Board[x][y].amount_of_fish == 1;
}

