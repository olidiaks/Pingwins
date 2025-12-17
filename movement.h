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
 * Checks if the current player is able to move any of their penguins.
 * A penguin can move if there are adjacent fields containing any fish.
 * The function iterates through all the penguins of the current player and
 * determines if at least one penguin has possible moves available.
 *
 * @param gameState A pointer to the GameState structure containing the current game's state,
 *                  including the board, players, and current player's data.
 * @return A boolean value indicating whether the current player can move any of their penguins.
 *         Returns true if at least one penguin has valid moves available, otherwise false.
 */
bool isPlayerAbleToMoveAnyPenguin(struct GameState* gameState);

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

/**
 * Prompts the current player to select which penguin they want to move.
 * Ensures the selected penguin is valid and has at least one possible move available.
 * If the player's input is invalid or the selected penguin cannot move, the function retries until valid input is provided.
 * Updates the game state to reflect the selected penguin for the current player.
 * @param gameState A pointer to the GameState structure that contains the current board, players, and game setup details.
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
bool check_adjacent_fish_availability(struct GameState* gameState, int x, int y);

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

#endif //PROJECT_MOVEMENT_H