//
// Created by theVo on 19/11/2025.
//

#ifndef PROJECT_CONSOLEVISUALIZATION_H
#define PROJECT_CONSOLEVISUALIZATION_H

#include <stdio.h>
#include "GameState.h"

/**
 * Displays the current game board along with player scores.
 * The board includes information about fish, penguins, and player ownership for each field.
 * Row and column indices are labeled alphabetically for easy reference.
 *
 * @param gameState A pointer to the GameState structure containing the current state of the game,
 *                  including board dimensions, player scores, player count, and the state of the game board.
 */
void showBoard(struct GameState *gameState);

/**
 * Prints information about the current state of the game to the console.
 * Information includes the current player's turn, the currently selected penguin,
 * and the total score (fish gathered) for each player.
 *
 * @param gameState A pointer to the GameState structure containing game details such as
 *                  the current player, player scores, and the number of players.
 */
void printGameInfo(struct GameState* gameState);

#endif //PROJECT_CONSOLEVISUALIZATION_H