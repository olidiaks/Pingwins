//
// Created by olidiaks on 17.12.2025.
//

#ifndef PROJECT_AUTONOMUS_PLACEMENT_H
#define PROJECT_AUTONOMUS_PLACEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "autonomousMode.h"

void countPenguins(struct GameState *gameState, int numOfPengiuns);

/**
 * Handles the autonomous placement of penguins in the game.
 * Reads the game state from an input file, processes the input, and writes the updated state to an output file.
 *
 * @param gameState Pointer to the GameState structure representing the current state of the game.
 * @param inputFilePath Path to the input file containing the initial game data.
 * @param outputFilePath Path to the output file where the updated game state will be written.
 * @param nameOfUs Name of the current team executing the function.
 * @param num_of_penguins
 */
void autonomousPlacement(struct GameState *gameState, char inputFilePath[], char outputFilePath[], char nameOfUs[],
                         char num_of_penguins[]);

/**
 * Automatically places a penguin for the current player in the game.
 * This function randomly selects a position on the board and ensures the placement
 * is valid, following the game's rules for coordinate and placement validity.
 *
 * @param gameState Pointer to the GameState structure containing the current game state,
 * including the board, players, and gameplay-related parameters.
 */
void placePenguinAutomatically(struct GameState *gameState);
#endif //PROJECT_AUTONOMUS_PLACEMENT_H
