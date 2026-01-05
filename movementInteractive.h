//
// Created by theVo on 19/11/2025.
//

#ifndef PROJECT_MOVEMENT_H
#define PROJECT_MOVEMENT_H

#include <stdbool.h>
#include "playerActions.h"
#include "consoleVisualization.h"
#include "main.h"
#include "GameState.h"
#include "placementInteractive.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * This function manages the interactive phase of the movement stage in the game.
 * It iteratively handles the process of moving players' penguins until no valid
 * moves are available for any player. For each turn, it ensures that the
 * current player has an opportunity to select and move one of their penguins
 * to a valid position on the board.
 *
 * During each player's turn, the function displays the game board and relevant
 * movement-phase information. It provides prompts for the player to select a
 * penguin and input the desired coordinates for moving it. Validation is performed
 * on the provided coordinates and moves, ensuring they adhere to game rules and
 * the board's constraints. If a move is invalid, the function prompts the player
 * again for correct input.
 *
 * After successfully moving a penguin, the function updates the game state,
 * including collecting fish, and rotates the play to the next player. The
 * movement phase ends when no penguins have valid moves remaining.
 *
 * @param gameState A pointer to the GameState structure containing the current
 *                  state of the game, including the board, players, and penguin
 *                  positions.
 */
void movementPhaseInteractiveMode(struct GameState *gameState);

/**
 * This function checks if there are any valid moves available for penguins on the board.
 * It iterates through all players and their penguins to determine if any penguin
 * has the option to move to an adjacent field with fish. The function stops checking
 * further when it finds the first penguin with a valid move.
 *
 * @param gameState A pointer to the GameState structure containing the current
 *                  state of the game, including the board, players, and penguin
 *                  positions.
 * @return A boolean-like integer value where 1 indicates that at least one penguin
 *         has a valid move available, and 0 indicates that no valid moves remain
 *         for any penguin.
 */
bool isThereAnyPenguinMoveAvailable(struct GameState *gameState);

/**
 * Determines if the current player is able to move any of their penguins to a
 * valid position on the board. For each penguin belonging to the current player,
 * it checks the adjacent tiles on the game board to see if there are available
 * moves that follow the rules of the game.
 *
 * This function plays a critical role in managing game flow by verifying whether
 * a player's turn can continue based on their ability to move at least one of
 * their penguins to a new, valid position.
 *
 * @param gameState A pointer to the GameState structure containing the current
 *                  state of the game, including information about the board,
 *                  players, and penguin positions.
 * @return A boolean value: true if the current player can move at least one of
 *         their penguins to a valid position, false otherwise.
 */
bool isPlayerAbleToMoveAnyPenguin(struct GameState *gameState);

/**
 * Handles the movement of a penguin in the game by updating its position on the
 * board and reflecting those changes in the game state. This function removes
 * the penguin from its current location, updates its position to the new coordinates,
 * and displays feedback on the action.
 *
 * The function uses the current player and their active penguin to determine
 * which piece to move. After updating the position, the game board's state along
 * with the player's penguin details are updated accordingly.
 *
 * @param gameState A pointer to the GameState structure containing the current
 *                  state of the game. This includes the board, players, and
 *                  information about their penguins.
 */
void movePenguin(struct GameState *gameState);

/**
 * This function prompts the current player to select a penguin to move during
 * their turn in the movement phase. It ensures that the selected penguin is valid
 * and able to perform at least one permissible move based on the current game state.
 *
 * The function queries the user for input, allowing them to specify which penguin
 * they wish to move by its numeric identifier. Validation is performed to ensure
 * the input corresponds to an existing penguin within the player's control. If the
 * selected penguin cannot move (i.e., no valid moves available), the function prompts
 * the user to choose another penguin.
 *
 * Iterative prompts ensure that only a valid, movable penguin is selected before
 * proceeding. The function updates the game state by recording the selected penguin
 * in the player's `currentPenguin` field within the `GameState` structure.
 *
 * @param gameState A pointer to the GameState structure containing information
 *                  about the current state of the board, players, and penguins.
 */
void askWhichPenguinMove(struct GameState *gameState);

/**
 * Checks if there are any adjacent tiles with available fish around the specified coordinates
 * on the game board. This function evaluates all four possible directions (top, bottom, left, right)
 * from the provided coordinates to determine the presence of fish on neighboring tiles.
 *
 * @param gameState A pointer to the GameState structure containing the board information.
 * @param x The x-coordinate of the tile to check around.
 * @param y The y-coordinate of the tile to check around.
 * @return A boolean value indicating whether there is at least one adjacent tile
 *         with available fish (true if fish are present, false otherwise).
 */
bool checkAdjacentFishAvailability(struct GameState *gameState, int x, int y);

/**
 * Determines if there is any possible move for the current penguin of the current player
 * by checking the availability of adjacent fields with fish.
 * The function retrieves the coordinates of the current penguin for the player whose turn
 * it is, then utilizes a helper function to verify if any of the neighboring tiles
 * contain fish.
 *
 * @param gameState A pointer to the GameState structure that contains the current state of the game,
 *                  including the board, players, and their respective penguins.
 * @return A non-zero value if there is at least one valid move for the current penguin,
 *         otherwise 0 if no moves are possible.
 */
bool isAnyMoveForCurrentPenguinAvailable(struct GameState *gameState);

/**
 * Removes a penguin from its current location on the board for the active player.
 * This involves updating the board to reset the field's player and penguin IDs
 * at the penguin's current coordinates.
 * No changes are made to the player's structure in this function.
 *
 * @param gameState A pointer to the GameState structure containing the current game state,
 *                  including the board, players, and their penguins.
 */
void removePenguinFromCurrentLocation(struct GameState *gameState);

#endif //PROJECT_MOVEMENT_H