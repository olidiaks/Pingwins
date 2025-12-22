//
// Created by theVo on 19/11/2025.
//

#ifndef PROJECT_CONSOLEVISUALIZATION_H
#define PROJECT_CONSOLEVISUALIZATION_H

#include <stdio.h>
#include "GameState.h"

/**
 * Displays the current state of the game board in the console.
 * The board includes a visual representation of tiles, penguins, and fish.
 * Player penguins and their respective IDs are also highlighted, along with
 * the fish count on tiles without penguins.
 *
 * @param gameState A pointer to the GameState structure containing details of the game,
 *                  such as the board dimensions, player information, and the board's state.
 */
void showBoard(struct GameState *gameState);

/**
 * Displays detailed information about the current game state in the console.
 * The information includes the current player, the active penguin being placed or moved,
 * and the current scores of all players.
 *
 * @param gameState A pointer to the GameState structure containing details about the game,
 *                  such as the current player, board state, player stats, and scores.
 */
void printGameInfo(struct GameState* gameState);

/**
 * Prints information about the current state of the game to the console during the movement phase
 * Information includes the current player's turn and the total score (fish gathered) for each player.
 *
 * @param gameState A pointer to the GameState structure containing game details such as
 *                  the current player, player scores, and the number of players.
 */
void printGameInfoMovement(struct GameState* gameState);

#endif //PROJECT_CONSOLEVISUALIZATION_H