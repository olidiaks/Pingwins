//
// Created by theVo on 19/11/2025.
//

#ifndef PROJECT_MOVEMENT_H
#define PROJECT_MOVEMENT_H

#include <stdbool.h>
#include "playerActions.h"
#include "consoleVisualization.h"
#include "main.h"

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
 */
void movementPhase(void);

/**
 * This function check if any player can make move.
 * @return Return true if penguin can be placed and false if not.
 */
bool isThereAnyPenguinMoveAvailable(void);

/**
 * This function check if player can make move.
 * @return Return true if player can move and false if can't.
 */
bool isPlayerMoveAvailable(void);

/**
 * This function moves the current player's penguin on the board.
 * It updates the game state by moving the penguin and prints a message.
 * The actual movement logic is handled by the caller.
 */
void movePenguin(void);

#endif //PROJECT_MOVEMENT_H