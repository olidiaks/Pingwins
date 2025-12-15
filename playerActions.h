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
 * @brief Validates if the coordinates of the current player's penguin are within the game board boundaries.
 *
 * This function verifies that the x and y coordinates of the current penguin
 * are greater than zero and less than the dimensions of the game board. It ensures
 * that the coordinates are located within the playable area.
 *
 * @param gameState A pointer to the GameState structure that contains the current
 *                  game board, players' data, and game state information.
 * @return True if the coordinates are valid, i.e., within the boundaries of the game board;
 *         otherwise, false.
 */
bool isCoordinateValid(struct GameState *gameState);

/**
 * @brief Places a penguin for the currently active player on the game board.
 *
 * This function sets the position of the penguin on the game board to the coordinates
 * specified by the current player's data and associates the penguin with the current
 * player in the game state. It updates the corresponding field on the board to reflect
 * the player's and penguin's identifiers.
 *
 * @param gameState A pointer to the GameState structure that contains the current
 *                  game board, players' data, and game state information.
 */
void placePenguin(struct GameState *gameState);

#endif //PROJECT_PLAYERACTIONS_H
