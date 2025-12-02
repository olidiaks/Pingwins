//
// Created by theVo on 19/11/2025.
//

#include "main.h"


int main(){
    srand(10);
    placementPhase(&gameState);
    if (isEveryPenguinsPlaced()) {
        movementPhase(&gameState);
        printf("The game was ended!\n");
    }
    else {
        printf("Not all penguins were placed.\n");
        return 1;
    }
    return 0;
}