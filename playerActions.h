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
 * @brief Handles input for coordinates during the game.
 *
 * This function prompts the user to input coordinates for a specific action
 * (e.g., placing or moving a penguin). It validates the input, converts the
 * alphanumeric coordinates to numerical indices, and updates the current player's
 * position in the game state. The calculated coordinates are applied to the active
 * player's data within the GameState structure.
 *
 * @param gameState A pointer to the GameState structure containing the current
 *                  game state, including the board and player data.
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
void changePenguinPosition(struct GameState *gameState);


/**
 * @brief Updates the current penguin index for the active player.
 *
 * This function increments the `currentPenguin` index for the currently active
 * player, allowing the game to track which penguin should be manipulated next.
 * It helps cycle through the penguins of the active player during game actions.
 *
 * @param gameState A pointer to the GameState structure that contains the current
 *                  game board, players' data, and game state information.
 */
void changeCurrentPenguin(struct GameState *gameState);

/**
 * @brief Determines if the attempted move for the active penguin is valid.
 *
 * This function evaluates whether the move specified by the active player's current
 * selection of coordinates is valid. It considers the rules of movement, such as
 * moving in a straight line along the board without skipping over empty or invalid tiles
 * (represented by fields with no fish). The move validity depends on the game's board state
 * and the selected penguin's current and target positions.
 *
 * @param gameState A pointer to the GameState structure that contains the current
 *                  game board, active player's data, and overall game state information.
 * @return True if the move is valid, otherwise false.
 */
bool isMoveValid(struct GameState *gameState);

/**
 * @brief Swaps the values of two integers if the first is greater than the second.
 *
 * This function compares two integers and swaps their values if the first integer
 * is greater than the second. It ensures that the smaller value is assigned to the
 * first variable and the larger value to the second.
 *
 * @param x A pointer to the first integer.
 * @param y A pointer to the second integer.
 */
void swapSmallerBiggerNumbers(int *x, int *y);

#endif //PROJECT_PLAYERACTIONS_H
