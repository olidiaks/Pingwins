//
// Created by theVo on 19/11/2025.
//

#ifndef PROJECT_CONSOLEVISUALIZATION_H
#define PROJECT_CONSOLEVISUALIZATION_H

#include <stdio.h>
#include "GameState.h"

/**
 * Displays the current state of the game board with all relevant information,
 * including the positions of penguins, fish counts on fields, and player scores.
 *
 * @param gameState A pointer to the GameState struct, containing all information
 *                   about the board, players, penguins, and game state.
 */
void showBoard(struct GameState *gameState);

#endif //PROJECT_CONSOLEVISUALIZATION_H