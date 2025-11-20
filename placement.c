//
// Created by theVo on 19/11/2025.
//

#include "placement.h"

void placementPhase() {
    readBoardDimensions();
    setCurrentPlayer();
    generateRandomBoard();
    while (canPlayerPlacePenguin()){
        showBoard();
        do{
            askCoordinates();
        } while (!isMoveValid());
        placePenguin();
        collectFish();
        canPlayerPlacePenguin();
        changeCurrentPlayer();
    }

}

int canPlayerPlacePenguin() {
    int chance = rand() % 20;
    return chance >= 1;
}

void placePenguin() {
    printf("Player %d 's penguin has been placed.\n",current_player+1);
}

bool isEveryPenguinsPlaced() {
    int chance = rand() % 2;
    return chance;
}