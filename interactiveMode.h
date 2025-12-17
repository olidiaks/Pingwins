//
// Created by olidiaks on 10.12.2025.
//


#ifndef PROJECT_INTERACTIVE_MODE_H
#define PROJECT_INTERACTIVE_MODE_H

#include "movementInteractive.h"
#include "placementInteractive.h"
#include "GameState.h"
#include <stdlib.h>

/**
 * Handles the interactive mode of the game, including initialization, placement phase,
 * movement phase, and displaying the game board. The function also determines the winner
 * based on the final scores of the players once the movement phase is completed.
 *
 * @param gameState Pointer to the GameState structure that holds the current state of the game,
 * including the board, players, penguins, and other game-related data.
 */
void interactive_mode(struct GameState *gameState);

#endif //PROJECT_INTERACTIVE_MODE_H