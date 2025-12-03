//
// Created by theVo on 19/11/2025.
//

#ifndef PROJECT_MAIN_H
#define PROJECT_MAIN_H

#include "movement.h"
#include "placement.h"
#include "GameState.h"

#include <stdlib.h>

extern struct GameState gameState;

/**
 * The entry point of the program. Initiates and runs the game by performing
 * the placement and movement phases. Determines the winner based on scores
 * or identifies whether a tie occurred. Handles early termination if all
 * penguins are not properly placed during the placement phase.
 *
 * @return 0 if the game executes successfully and proceeds through all phases,
 *         1 if not all penguins are placed.
 */
int main();


#endif //PROJECT_MAIN_H