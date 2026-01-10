//
// Created by olidiaks on 17.12.2025.
//

#ifndef PROJECT_AUTONOMUS_PLACEMENT_H
#define PROJECT_AUTONOMUS_PLACEMENT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autonomousMode.h"
#include "binnaryTree.h"

typedef enum { NONE, UP, DOWN, LEFT, RIGHT } Direction;

/**
 * Counts the number of penguins placed on the board for the current player
 * and verifies if the desired number of penguins has been placed.
 *
 * @param gameState Pointer to the GameState structure representing the current state of the game.
 * @param numOfPengiuns The total number of penguins the current player is expected to place on the board.
 */
void countPenguins(struct GameState *gameState, int numOfPengiuns);

/**
 * Executes the autonomous placement phase in the game by reading the input file
 * to initialize the game state, counting the penguins placed by the current player,
 * and automatically placing remaining penguins on the board.
 * The final board state is then written to the output file.
 *
 * @param gameState Pointer to the GameState structure that holds the current state of the game.
 * @param inputFilePath File path of the input file containing the initial game configuration.
 * @param outputFilePath File path where the final game state will be written.
 * @param nameOfUs The name of the current team performing the autonomous placement.
 * @param num_of_penguins Array representing the number of penguins to be placed during this phase.
 */
void autonomousPlacement(struct GameState *gameState, char inputFilePath[], char outputFilePath[], char nameOfUs[],
                         char num_of_penguins[]);

/**
 * Places a penguin automatically for the current player on the board.
 * The penguin is placed on the first available tile with exactly one fish.
 * Updates the player's position and collects fish from the selected tile.
 * If no suitable position is found, the game will terminate with an error.
 *
 * @param gameState Pointer to the GameState structure representing the current state of the game.
 */
void placePenguinAutomatically(struct GameState *gameState);

int scorePlacement(struct GameState *game_state, int x, int y, struct Node *binaryTree, int depth);

#endif //PROJECT_AUTONOMUS_PLACEMENT_H
