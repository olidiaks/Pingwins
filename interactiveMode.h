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
 * Handles the interactive mode of the game.
 *
 * This function initializes the game environment, facilitates the placement
 * of penguins on the game board, and manages the movement phase of the game
 * interactively. It also determines the result of the game and announces
 * the winner at the end. If penguins are not properly placed, the game will
 * terminate with an error.
 *
 * @param gameState Pointer to the GameState structure that contains the
 *        current state of the game, including player data, board configuration,
 *        and game settings.
 */
void interactiveMode(struct GameState *gameState);

/**
 * Announces the winner of the game based on the current scores of the players.
 *
 * This function compares the scores of the players stored in the game state
 * and announces the winner. If the scores are equal, it declares the game as a tie.
 *
 * @param gameState Pointer to the GameState structure that contains information
 *        about the current game, including player scores and other game details.
 */
void show_winner_announcement(struct GameState *gameState);

#endif //PROJECT_INTERACTIVE_MODE_H