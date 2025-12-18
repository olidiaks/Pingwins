//
// Created by olidiaks on 10.12.2025.
//

#ifndef PROJECT_AUTONOMOUS_MODE_H
#define PROJECT_AUTONOMOUS_MODE_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


#include "GameState.h"



/**
 * Opens an output file in write mode, checks for errors, and handles them appropriately.
 *
 * If the file cannot be opened (e.g., due to an incorrect path or insufficient
 * permissions), the function will print an error message and terminate the program
 * with an exit code of 3.
 *
 * @param filePath The name or path of the output file to be opened.
 * @return A pointer to the opened output file.
 * @throws Exits the program on error with exit code 3, and prints an error message.
 */
FILE *openOutputFileAndHandleError(char *filePath);

/**
 * Opens an input file in read mode, validates its content for correctness, and handles errors appropriately.
 *
 * This function ensures that the input file:
 * 1. Exists and can be successfully opened.
 * 2. Has a valid header with the correct dimensions.
 * 3. Has matching dimensions for the reported size.
 * 4. Maintains rectangular consistency in its structure.
 * 5. Abides by the zero placement constraint.
 *
 * If any of these checks fail, the function will print an error message and terminate the program
 * with an appropriate exit code:
 * - Exit code 3: Failed to open the file.
 * - Exit code 2: File structure or content validation issues.
 *
 * @param filePath The path to the input file to be opened and validated.
 * @return A pointer to the opened and validated input file.
 * @throws Exits the program with an error code and prints an appropriate error message upon failure.
 */
FILE *openInputFileAndHandleError(char *filePath);

/**
 * Reads and processes game board data from a file to populate the game state.
 *
 * The method reads a file containing information about the map dimensions
 * (number of rows and columns) and the distribution of fish on the board.
 * It initializes the game board and updates the relevant fields in the
 * provided game state structure. If the file contains improperly formatted
 * data or exceeds the expected dimensions, the behavior may be undefined.
 * The board is represented as a 2D array of `Field` structures within
 * the game state.
 *
 * @param givenFile A pointer to the file to be read. The file should contain
 *                  the map dimensions on the first line, followed by rows of
 *                  space-separated integers specifying the number of fish in
 *                  each cell.
 * @param gameState A GameState structure that holds the state of the game,
 *                  including the board dimensions and fields. The structure
 *                  will be modified to reflect the data read from the file.
 * @return A character status indicating the result of the file processing.
 *         The specific meaning of the returned character depends on the
 *         implementation.
 */
char readFile(FILE *givenFile, struct GameState *gameState);

/**
 * Loads player data from a given input file into the game state and determines
 * if the user's team is present in the list of players.
 *
 * The function reads player data from the provided file in the format:
 * player_nick_name id score. It ensures that data is correctly organized.
 * If the user's team is found on the list, relevant fields in the game state
 * are updated. Improper file format or memory allocation issues will cause
 * the program to terminate with an error message.
 *
 * @param game_state Pointer to the GameState structure that stores the game's current state.
 * @param input_file The file pointer to the input file containing player data.
 * @return A boolean value indicating whether the user's team is present in the file (true if found, false otherwise).
 * @throws Exits the program if the file data format is incorrect (exit code 2) or if memory allocation for players
 * fails (exit code 2 or 3).
 */
bool loadPlayers(struct GameState *game_state, FILE *input_file);

#endif //PROJECT_AUTONOMOUS_MODE_H
