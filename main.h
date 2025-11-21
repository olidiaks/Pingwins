//
// Created by theVo on 19/11/2025.
//

#ifndef PROJECT_MAIN_H
#define PROJECT_MAIN_H

#include "movement.h"
#include "placement.h"

#include <stdlib.h>

extern int current_player;

/**
 * @brief The entry point for the game application.
 *
 * This function initializes the game's execution by setting a fixed seed for randomness,
 * invoking the penguin placement phase, verifying whether all penguins have been placed,
 * and proceeding to the movement phase if the placement conditions are met.
 *
 * @return Returns 0 if the game ends successfully, or 1 if not all penguins were placed.
 */
int main();


#endif //PROJECT_MAIN_H