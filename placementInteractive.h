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
 * @brief Manages the interactive placement mode where players place penguins on the board.
 *
 * This function initiates the interactive placement phase of the game, where players
 * take turns placing their penguins on the board according to game rules. It handles
 * board generation, coordinate input, placement validation, and updates game state
 * details such as player turns and penguin placement. The function continues looping
 * until all penguins are placed or no valid moves are available for players.
 *
 * @param gameState A pointer to the GameState structure containing the current game state,
 *                  including the board, players, and relevant game parameters.
 */
void placementInteractiveMode(struct GameState *gameState);

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
 * @brief Validates if the current player's penguin placement is allowed on the board.
 *
 * This function checks whether the tile at the current player's intended placement
 * coordinates is a valid location for placing a penguin. Validity is determined based
 * on the rules that the tile must contain exactly one fish and no other penguins.
 *
 * @param gameState A pointer to the GameState structure containing the current state of the game,
 *                  including the board, players, and game parameters.
 * @return Returns true if the placement is valid (i.e., the tile contains exactly one fish),
 *         and false otherwise.
 */
bool isPlacementValid(struct GameState *gameState);

/**
 * @brief Places a penguin for the current player on the specified board location.
 *
 * Updates the game state by placing the current player's penguin on the selected
 * and validated board coordinates. After placing the penguin, it adjusts the penguin's
 * position in the game state and provides feedback about the placement. This function
 * is typically called only after validating the placement location and the player's turn.
 *
 * @param gameState A pointer to the GameState structure containing the current game state,
 *                  including the board, players, and other game parameters.
 */
void placePenguin(struct GameState *gameState);

#endif //PROJECT_PLACEMENT_H