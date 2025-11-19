//
// Created by theVo on 19/11/2025.
//

#include "main.h"
#include "playerActions.h"

#include "stdio.h"
#include "stdlib.h"

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

int ValidCoordinates() {
    int chance = rand() % 5;
    return chance >= 1;
}