//
// Created by olidiaks on 17.12.2025.
//

#ifndef PROJECT_AUTONOMUSMOVEMENT_H
#define PROJECT_AUTONOMUSMOVEMENT_H

#include "autonomousMode.h"
#include  "GameState.h"

/**
 * Writes the current board state and player information to a specified file.
 *
 * The function outputs the board dimensions, the state of each field on the board
 * (including the amount of fish and player-related data), and player information
 * such as names, IDs, and scores. The data is written in a structured format
 * that can later be parsed to recreate the game state.
 *
 * @param outputFile A pointer to the file where the board state will be written.
 *                   Must be a valid file pointer.
 * @param gameState  A pointer to the GameState structure containing the board,
 *                   players, and other relevant game information to be written to the file.
 */
void writeBoardToFile(FILE *outputFile, struct GameState *gameState);

/**
 * Handles the autonomous movement phase of the game by reading the current
 * game state from a specified input file, processing it, and writing updates
 * back to an output file.
 *
 * This function reads the game state data, processes movements based on the
 * game's rules, and saves the updated state to the output file. It ensures
 * proper management of file I/O, error handling, and data integrity when
 * interacting with the game state.
 *
 * @param gameState A pointer to the GameState structure that holds the current
 *                  state of the game, including the board, players, and related information.
 * @param inputFilePath A null-terminated string specifying the file path for the
 *                      input file containing the game state to be read.
 * @param outputFilePath A null-terminated string specifying the file path for
 *                       the output file where the updated game state will be written.
 * @param nameOfUs A null-terminated string specifying the team's name, which is
 *                 used for identifying the autonomous player performing the movements.
 */
void autonomousMovement(struct GameState *gameState, char inputFilePath[], char outputFilePath[], char nameOfUs[]);

#endif // PROJECT_AUTONOMUSMOVEMENT_H
