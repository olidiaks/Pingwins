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
 * @brief Collects fish for the current player based on their position on the board.
 *
 * This function adds the number of fish present on the tile where the current player's penguin
 * is located to the player's total score. It then resets the number of fish on that tile to zero
 * and displays a message indicating the fish collection event.
 *
 * @param gameState A pointer to the GameState structure that holds information about the board,
 *                  the current player, and player data such as positions and scores.
 */
void collectFish(struct GameState *gameState);

/**
 * @brief Switches the game to the next player's turn.
 *
 * This function updates the current player index in the game state to the next player in the
 * turn order. The player index wraps around to the first player after the last player, ensuring
 * cyclic turn management. It also displays a message indicating the new current player.
 *
 * @param gameState A pointer to the GameState structure that holds information about the
 *                  current player, total number of players, and other game-related data.
 */
void changeCurrentPlayer(struct GameState *gameState);

/**
 * @brief Prompts the player to enter coordinates and updates the current player's position.
 *
 * This function interacts with the player to input coordinates for a desired action, such as
 * placing or moving a penguin. It validates the provided coordinates and updates the current
 * player's x and y positions in the GameState structure accordingly. If the input is invalid,
 * the player's position is set to -1 for both x and y, signaling an error state.
 *
 * @param gameState A pointer to the GameState structure containing the game board, players,
 *                  and relevant game data.
 */
void askCoordinates(struct GameState *gameState);

/**
 * @brief Checks if the current player's coordinates are within the bounds of the game board.
 *
 * This function validates whether the current player's x and y coordinates are within the
 * dimensions of the game board. It ensures the coordinates are non-negative and less than
 * the respective board size limits.
 *
 * @param gameState A pointer to the GameState structure that contains the board dimensions,
 *                  player data, and current player information.
 * @return True if the coordinates are valid, i.e., within the board's bounds; false otherwise.
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
 * @brief Validates whether a player's attempted penguin movement is legal based on the game rules.
 *
 * This function checks if the requested movement for the current player's selected penguin adheres
 * to the game rules. It ensures that:
 * - The movement is either horizontal or vertical, not diagonal.
 * - The destination tile contains fish and is free of other penguins.
 * - The path to the destination tile is clear and does not cross any empty tiles.
 *
 * @param gameState A pointer to the GameState structure that contains the current state of the game,
 *                  including the board, player data, and penguin positions.
 * @return true if the move is valid, false otherwise.
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
void swapSmallerWithBiggerNumbers(int *x, int *y);

#endif //PROJECT_PLAYERACTIONS_H
