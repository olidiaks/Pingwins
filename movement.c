//
// Created by theVo on 19/11/2025.
//

#include "movement.h"

void movementPhase() {
    while(isThereAnyPenguinMoveAvailable()){
        bool hasCurrentPlayerMoved = false;
        while(isPlayerMoveAvailable()){
            showBoard();
            do {
                askCoordinates();
            } while (!isMoveValid());
            movePenguin();
            collectFish();
        }
        changeCurrentPlayer();
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

void movePenguin() {
    printf("Player %d 's penguin has been moved.\n",current_player+1);
}