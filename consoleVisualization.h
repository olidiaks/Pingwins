//
// Created by theVo on 19/11/2025.
//

#ifndef PROJECT_CONSOLEVISUALIZATION_H
#define PROJECT_CONSOLEVISUALIZATION_H

#include <stdio.h>
#include "GameState.h"

/**
 * @brief Displays the current state of the game board.
 *
 * This function prints a textual representation of the board to
 * standard output. It is called during both the placement and movement
 * phases to provide the player with a visual overview of penguins,
 * fish, and empty tiles.
 *
 * @param gameState A pointer to the GameState structure containing the board dimensions.
 *
 * @return void
 */
void showBoard(struct GameState *gameState);

#endif //PROJECT_CONSOLEVISUALIZATION_H