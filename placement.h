//
// Created by theVo on 19/11/2025.

#ifndef PROJECT_PLACEMENT_H
#define PROJECT_PLACEMENT_H

#include <stdbool.h>
#include "GameState.h"
#include "main.h"
#include "playerActions.h"
#include "boardGeneration.h"
#include "consoleVisualization.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Handles the game's placement phase where players alternately place penguins on the board.
 *
 * This function starts the game by reading the board dimensions, initializing the current player,
 * and generating a random board. It then enters a loop where it repeatedly:
 * - Displays the current board state.
 * - Asks the current player for coordinates until a valid move is provided.
 * - Places the penguin according to the player's input.
 * - Collects fish from the placed penguin.
 * - Checks if the current player can place another penguin.
 * - Switches to the next player.
 *
 * The loop continues until no valid moves are left or all penguins are placed.
 * @param gameState A pointer to the GameState structure containing the board dimensions.
 */
void placementPhase(struct GameState *gameState);

/**
 * @brief Checks if the current player is able to place any penguins on the board.
 *
 * This function evaluates whether there are valid board positions available for the
 * current player to place penguins. It iterates through the board, counting fields
 * that do not contain any fish. The function returns false if all fields are empty
 * or if the required penguins for all players are already placed.
 *
 * @param gameState A pointer to the GameState structure containing the board and game details.
 * @return An integer value indicating whether the player can place penguins:
 *         1 if the player can place a penguin, 0 otherwise.
 */
bool canPlayerPlacePenguin(struct GameState *gameState);


/**
 * @brief Checks if all penguins have been placed during the placement phase.
 *
 * This function returns true if every penguin has been placed, and false otherwise.
 *
 * @return true if all penguins are placed, false otherwise.
 */
bool isEveryPenguinsPlaced(struct GameState *gameState);

/**
 * @brief Checks if the penguin placement at the current coordinates is valid.
 *
 * Validates whether the current player's penguin can be placed on the board
 * at its current position. A placement is considered valid when the field
 * has exactly one fish and no other penguins are already occupying that field.
 *
 * @param gameState A pointer to the GameState structure containing information
 *                  about the board, players, and their positions.
 * @return Returns 1 if the placement is valid; otherwise, returns 0.
 */
bool isPlacemntVaild(struct GameState *gameState);

#endif //PROJECT_PLACEMENT_H