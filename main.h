//
// Created by theVo on 19/11/2025.
//

#ifndef PROJECT_MAIN_H
#define PROJECT_MAIN_H

#include "interactive_mode.h"
#include <stdlib.h>
#include "autonomus_mode.h"


extern struct GameState gameState;

/**
 * @brief The entry point of the program. Initializes the game by seeding the random number generator
 *        and invoking the interactive game mode with the game state.
 *
 * The function sets a fixed seed for the random number generator to ensure deterministic behavior
 * during program execution. It then calls the interactive_mode function to start the game, passing
 * the global gameState as a parameter, and returns 0 to indicate successful execution.
 *
 * @return int Returns 0 upon successful execution of the program.
 */

int main(int argc, char *argv[]);


#endif //PROJECT_MAIN_H
