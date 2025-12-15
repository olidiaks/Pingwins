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

#endif //PROJECT_CONSOLEVISUALIZATION_H