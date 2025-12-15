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
 * This function determines if there are any penguin moves available for any player in the game.
 * For each player's penguins, it checks if there are adjacent fields on the board containing fish.
 * A valid move exists if at least one adjacent field in any direction (left, top, bottom, right)
 * has one or more fish.
 *
 * The function iterates through all players and their penguins, examining the board dimensions
 * and the fish count in each adjacent field to validate the availability of a move.
 *
 * @param gameState A pointer to the GameState structure containing the board state, players,
 *                  and their respective penguins.
 * @return Returns true if at least one valid move is available; otherwise, returns false.
 */
bool isThereAnyPenguinMoveAvailable(struct GameState *gameState);

/**
 * This function check if player can make move.
 * @return Return true if player can move and false if can't.
 */
bool isPlayerMoveAvailable(void);

/**
 * This function moves the currently selected penguin for the active player
 * during their turn in the game's movement phase. It performs the necessary
 * updates to the penguin's position on the game board and logs the action.
 *
 * @param gameState A pointer to the GameState structure that maintains the
 *                  current state of the game, including player information,
 *                  board configuration, and penguin positions.
 */
void movePenguin(struct GameState *gameState);

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
bool check_adjacent_fish_availability(struct GameState* gameState, int x, int y);

#endif //PROJECT_MOVEMENT_H