//
// Created by theVo on 19/11/2025.
//

#include "main.h"

int current_player = 0;


int main(){
    srand(10);
    placementPhase();
    if (isEveryPenguinsPlaced()) {
        movementPhase();
        printf("The game was ended!\n");
    }
    else {
        printf("Not all penguins were placed.\n");
        return 1;
    }
    return 0;
}