//
// Created by theVo on 19/11/2025.

#ifndef PROJECT_PLACEMENT_H
#define PROJECT_PLACEMENT_H

#include <stdbool.h>
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
 * @brief Places a penguin on the board for the current player.
 *
 * This function updates the board state by placing the current player's penguin at the specified coordinates.
 * It then triggers the collection of fish from the placed penguin's position.
 * The function is called after a valid move is confirmed and is part of the game's placement phase loop.
 *
 * @param gameState A pointer to the GameState structure containing the board dimensions.
 */
void placePenguin(struct GameState *gameState);

/**
 * @brief Checks if all penguins have been placed during the placement phase.
 *
 * This function returns 1 if every penguin has been placed, and 0 otherwise.
 *
 * @return 1 if all penguins are placed, 0 otherwise.
 */
bool isEveryPenguinsPlaced(struct GameState *gameState);

#endif //PROJECT_PLACEMENT_H