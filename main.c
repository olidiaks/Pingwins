//
// Created by theVo on 19/11/2025.
//

#include "main.h"

int current_player = 0;

/**
 * @brief The entry point for the game application.
 *
 * This function initializes the game's execution by setting a fixed seed for randomness,
 * invoking the penguin placement phase, verifying whether all penguins have been placed,
 * and proceeding to the movement phase if the placement conditions are met.
 *
 * @return Returns 0 if the game ends successfully, or 1 if not all penguins were placed.
 */
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