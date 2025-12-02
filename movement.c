//
// Created by theVo on 19/11/2025.
//

#include "movement.h"

void movementPhase(struct GameState *gameState) {
    while(isThereAnyPenguinMoveAvailable()){
        bool hasCurrentPlayerMoved = false;
        while(isPlayerMoveAvailable()){
            showBoard(gameState);
            do {
                askCoordinates();
            } while (!isMoveValid());
            movePenguin(gameState);
            collectFish(gameState);
        }
        changeCurrentPlayer(gameState);
    }
}

bool isThereAnyPenguinMoveAvailable() {
    int chance = rand() % 50;
    return chance >= 1;
}

bool isPlayerMoveAvailable() {
    int chance = rand() % 2;
    return chance == 1;
}

void movePenguin(struct GameState *gameState) {
    printf("Player %d 's penguin has been moved.\n", gameState->current_player + 1);
}
