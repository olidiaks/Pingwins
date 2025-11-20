//
// Created by theVo on 19/11/2025.
//

#include "playerActions.h"


void collectFish() {
    printf("Player %d has collected fish.\n",CurrentPlayer+1);
}

void SetCurrentPlayer() {
    CurrentPlayer = 0;
}

void changeCurrentPlayer() {
    CurrentPlayer = !CurrentPlayer;
    printf("Changing players...\n");
}

void askCoordinates() {

}

int areValidCoordinates() {
    int chance = rand() % 5;
    return chance >= 1;
}