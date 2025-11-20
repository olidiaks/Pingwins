//
// Created by theVo on 19/11/2025.
//

#include "movement.h"

void movementPhase() {
    while(canAnyPenguinBeMoved()){
        bool hasCurrentPlayerMoved = false;
        while(canCurrentPlayerMove()){
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

bool canAnyPenguinBeMoved() {
    int chance = rand() % 50;
    return chance >= 1;
}

int canCurrentPlayerMove() {
    int chance = rand() % 2;
    return chance == 1;
}

void movePenguin() {
    printf("Player %d 's penguin has been moved.\n",current_player+1);
}