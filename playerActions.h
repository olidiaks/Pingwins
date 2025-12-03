//
// Created by theVo on 19/11/2025.
//

#ifndef PROJECT_PLAYERACTIONS_H
#define PROJECT_PLAYERACTIONS_H

#include <ctype.h>

#include "main.h"
#include "stdio.h"
#include "stdlib.h"
#include <stdbool.h>
#include "GameState.h"

/**
 * @brief Collects fish from the current position of the active player's penguin.
 *
 * This function updates the game state by adding the amount of fish from the
 * current position of the active player's penguin to their score. The corresponding
 * field on the board is reset to indicate that the fish have been collected. A message
 * is printed to indicate the action for the current player.
 *
 * @param gameState A pointer to the GameState structure that contains the current
 *                  game board, players' data, and game state information.
 */
void collectFish(struct GameState *gameState);

/**
 * @brief Changes the current player in the game.
 *
 * This function updates the current player in the game state to the next player
 * in a round-robin fashion. It ensures that the turn rotates among all players
 * and prints the updated current player's information.
 *
 * @param gameState A pointer to the GameState structure containing the current player
 *                  and the number of players in the game.
 */
void changeCurrentPlayer(struct GameState *gameState);

/**
 * @brief Prompts the current player to input coordinates and updates the game's state accordingly.
 *
 * This function asks the current player for input to specify the coordinates of a target cell
 * on the game board. It processes the player's input, validates it, and updates the position
 * of the player’s penguin in the game state.
 *
 * @param gameState A pointer to the GameState structure, containing information about
 * the current game state, including the board configuration, players, and penguin positions.
 */
void askCoordinates(struct GameState *gameState);

/**
 * @brief Verifies if a player's move is valid within the game board boundaries.
 *
 * This function checks whether the coordinates of the current player's penguin are within
 * the valid range of the game board dimensions, ensuring the move remains inside the board.
 *
 * @param gameState A pointer to the GameState structure containing the game board and player details.
 * @return A boolean value indicating whether the move is valid (true) or invalid (false).
 */
bool isMoveValid(struct GameState* gameState);

#endif //PROJECT_PLAYERACTIONS_H