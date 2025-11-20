//
// Created by theVo on 19/11/2025.
//

#include "main.h"

int CurrentPlayer = 0;

int main(){
    srand(10);
    PlacementPhase();
    if (isEveryPenguinsPlaced()) {
        MovementPhase();
        printf("The game was ended!\n");
    }
    else {
        printf("Not all penguins were placed.\n");
        return 1;
    }
    return 0;
}