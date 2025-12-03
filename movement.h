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
#include "placement.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/**
 * This function handles the game's movement phase where players take turns moving penguins.
 * It continues looping until no more valid moves are available for any player.
 * For the current player, it processes moves until they have successfully moved or no more moves are available.
 * Each move involves displaying the board, prompting the player for coordinates, validating the move,
 * executing the move, and collecting any fish.
 * After the current player completes their moves, the turn passes to the next player.
 * @param gameState A pointer to the GameState structure containing the board dimensions.
 */
void movementPhase(struct GameState *gameState);

/**
 * Checks if there are any valid moves available for penguins on the game board.
 * This is determined by verifying whether any board cell has fish available.
 * If all cells have zero fish, it indicates no moves are possible for any player.
 *
 * @param gameState A pointer to the GameState structure containing the board state
 *                  and game parameters, including board size and its fields.
 * @return Returns 1 if there are valid moves available; otherwise, returns 0.
 */
bool isThereAnyPenguinMoveAvailable(struct GameState *gameState);

/**
 * This function check if player can make move.
 * @return Return true if player can move and false if can't.
 */
bool isPlayerMoveAvailable(void);

/**
 * This function moves the current player's penguin on the board.
 * It updates the game state by moving the penguin and prints a message.
 * The caller handles the actual movement logic.
 *
 * @param gameState A pointer to the GameState structure containing the board dimensions.
 */
void movePenguin(struct GameState *gameState);

#endif //PROJECT_MOVEMENT_H