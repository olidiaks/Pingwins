//
// Created by theVo on 19/11/2025.
//

#include "placement.h"

void PlacementPhase() {
    ReadBoardDimensions();
    SetCurrentPlayer();
    GenerateRandomBoard();
    while (canPlayerPlacePenguin()){
        ShowBoard();
        do{
            askCoordinates();
            areValidCoordinates();
        } while (!areValidCoordinates());
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
    printf("Player %d 's penguin has been placed.\n",CurrentPlayer+1);
}

bool isEveryPenguinsPlaced() {
    int chance = rand() % 2;
    return chance;
}