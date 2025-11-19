//
// Created by theVo on 19/11/2025.
//

#include "main.h"
#include "movement.h"
#include "placement.h"

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int CurrentPlayer = 0;

int main() {
    srand(time(NULL));
    PlacementPhase();
    if(allPenguinsPlaced()){
        printf("Penguins were placed successfully. Moving onto the Movement Phase.\n");
        MovementPhase();
        if(!canAnyPenguinBeMoved()){
            printf("The game has ended.\n");
        }
    }
    else
        printf("Error.\n");
    return 0;
}