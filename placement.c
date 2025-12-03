//
// Created by theVo on 19/11/2025.
//

#include "placement.h"

void placementPhase(struct GameState *gameState) {
    readBoardDimensions(gameState);
    generateRandomBoard(gameState);
    while (canPlayerPlacePenguin()){
        showBoard(gameState);

        char x[2], y[2];

        do{
            askCoordinates(gameState);
        } while (!isMoveValid(x, y, gameState));
        placePenguin(gameState);
        collectFish(gameState);
        canPlayerPlacePenguin();
        changeCurrentPlayer(gameState);
    }

}

bool canPlayerPlacePenguin()
{
    int chance = rand() % 20;
    return chance >= 1;
}

void placePenguin(struct GameState *gameState) {
    printf("Player %d 's penguin has been placed.\n", gameState->current_player + 1);
}

bool isEveryPenguinsPlaced() {
    int chance = rand() % 2;
    return chance;
}