//
// Created by theVo on 19/11/2025.
//

#include "main.h"
#include "placement.h"
#include "playerActions.h"
#include "boardGeneration.h"
#include "consoleVisualization.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void PlacementPhase() {
    ReadBoardDimensions();
    SetCurrentPlayer();
    GenerateRandomBoard();
    while (canPlayerPlacePenguin()){
        ShowBoard();
        do{
            askCoordinates();
            ValidCoordinates();
        } while (!ValidCoordinates());
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