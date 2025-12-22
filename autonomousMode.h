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

#include "boardGeneration.h"
#include "loadValidator.h"
#include "main.h"

#include "GameState.h"

/**
 * Writes the current game state, including board configuration and player details, to an output file.
 *
 * The function processes the game board dimensions, the board fields (amount of fish and player ID),
 * and enumerates player details such as their name, score, and identifier. The output is formatted
 * into the specified file, preserving the structure needed for subsequent processing or review.
 *
 * If the output file pointer is null, an error message is printed to `stderr`, and the function returns
 * without attempting to write.
 *
 * @param outputFile A pointer to the file where the game state will be written. The file must already
 *                   be open and writable.
 * @param gameState A pointer to the GameState structure that contains the game data to be written.
 *                  This includes board dimensions, board state, and player information.
 */
void writeBoardToFile(FILE *outputFile, struct GameState *gameState);


/**
 * Opens an output file at the specified file path for writing. If the file cannot be opened,
 * the function displays an error message and terminates the program.
 *
 * This function attempts to create or open the specified file in write mode. If any issue occurs
 * (e.g., incorrect path or insufficient permissions), an error message is printed, and the program exits
 * with an error code. The returned file pointer allows subsequent writing operations to the file.
 *
 * @param filePath A pointer to a character string representing the full path of the output file to open.
 *                 The path should be valid and writable by the program.
 * @return A pointer to the opened FILE object. If the function cannot open the file, the
 *         program exits before returning.
 */
FILE *openOutputFileAndHandleError(char *filePath);

/**
 * Opens an input file and performs a series of validation checks to ensure its correctness.
 *
 * The function attempts to open the provided file path for reading. If the file cannot be opened,
 * an error message is printed, and the program exits with an error code. After opening the file,
 * a sequence of validation checks is performed to verify the file's integrity and ensure compliance
 * with the expected structure and constraints.
 *
 * If any of the validation checks fail, appropriate error messages are printed to `stderr`,
 * and the program exits with an error code. Successful validation results in the return
 * of the opened file pointer.
 *
 * @param filePath The path to the input file to be opened and validated. This should point to
 *                 a valid, readable file.
 * @return A pointer to the opened file, ensuring it has passed all validation checks.
 *         If the validation fails or the file cannot be opened, the program terminates.
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
 * Loads player data from the provided input file into the given game state.
 *
 * This function initializes the players in the game state, reading their data
 * (name, ID, and score) from the input file. If any errors occur during the
 * process (e.g., invalid format, out-of-bounds player ID, or memory allocation
 * failure), the function will print an appropriate error message and terminate
 * the program with a specific exit code.
 *
 * @param game_state A pointer to the GameState structure where the player data
 *                   will be stored.
 * @param input_file A pointer to the file containing player data to be loaded.
 * @return True if all players are successfully loaded; otherwise, exits the
 *         program with an error message.
 */
bool loadPlayers(struct GameState *game_state, FILE *input_file);

#endif //PROJECT_AUTONOMOUS_MODE_H
