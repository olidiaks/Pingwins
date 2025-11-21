//
// Created by theVo on 19/11/2025.

#ifndef PROJECT_PLACEMENT_H
#define PROJECT_PLACEMENT_H

#include <stdbool.h>
#include "main.h"
#include "playerActions.h"
#include "boardGeneration.h"
#include "consoleVisualization.h"

#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Manages the placement phase of the game where players place penguins on the board.
 *
 * This function orchestrates all steps necessary for the placement phase of the game. It begins by reading
 * board dimensions and setting the current player. A random board is generated for the players to start with.
 * The placement continues in a loop as long as the player can place penguins. Within the loop, the board is
 * displayed, players are prompted for coordinates, and the validity of chosen moves is verified. If the move
 * is valid, a penguin is placed, and fishes are collected. After processing the player's action, the player
 * is switched for the next turn.
 */
void placementPhase(void);

int canPlayerPlacePenguin(void);

void placePenguin(void);

bool isEveryPenguinsPlaced(void);

#endif //PROJECT_PLACEMENT_H