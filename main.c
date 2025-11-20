//
// Created by theVo on 19/11/2025.
//

#include "main.h"

int CurrentPlayer = 0;

int main() {
    srand(1);
    PlacementPhase();
    if (isEveryPenguinsPlaced()) {
        MovementPhase();
    }
    else {
        printf("Not all penguins were placed.\n");
    }
    return 0;
}