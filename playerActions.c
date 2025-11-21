//
// Created by theVo on 19/11/2025.
//

#include "playerActions.h"


void collectFish() {
    printf("Player %d has collected fish.\n",current_player+1);
}

void setCurrentPlayer() {
    current_player = 0;
}

void changeCurrentPlayer() {
    current_player = !current_player;
    printf("Changing players...\n");
}

void askCoordinates() {

}

bool isMoveValid()
{
    int chance = rand() % 5;
    return chance >= 1;
}
