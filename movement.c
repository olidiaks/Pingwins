//
// Created by theVo on 19/11/2025.
//

#include "movement.h"

void MovementPhase() {
    while(canAnyPenguinBeMoved()){
        bool hasCurrentPlayerMoved = false;
        while(canCurrentPlayerMove()){
            ShowBoard();
            do {
                askCoordinates();
            } while (!ValidCoordinates());
            movePenguin();
            collectFish();
            changeCurrentPlayer();
            hasCurrentPlayerMoved = true;
        }
        if (!hasCurrentPlayerMoved) {
            changeCurrentPlayer();
        }
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
    printf("Player %d 's penguin has been moved.\n",CurrentPlayer+1);
}