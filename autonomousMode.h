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
 * Loads the board configuration and dimensions from an input file and updates the given game state.
 *
 * This function reads the board dimensions from the first line of the file and initializes the game
 * state's board with the specified dimensions. It then populates each cell of the board based on
 * subsequent lines in the file, where each cell contains the amount of fish and the player ID.
 *
 * The function assumes that the input file is organized in the following format:
 * - The first line specifies the number of rows and columns of the board, separated by a space.
 * - Each subsequent line corresponds to a row of the board where each cell's value is represented
 *   as a number. The number is split into two parts: the number of fish (tens place) and the player ID (units place).
 *
 * Debug output displaying the internal board state is printed to the console for verification.
 * The board is allocated and initialized using the `generateVoidBoard` function.
 *
 * @param givenFile A pointer to the input file to be read. The file must be open and readable.
 * @param gameState A pointer to the GameState structure where the parsed board data and dimensions
 *                  will be stored. The board is initialized within this structure.
 *
 */
void loadBoard(FILE *givenFile, struct GameState *gameState);

/**
 * Loads player data from the provided input file into the game state structure.
 *
 * This function parses the input file to initialize player configuration in the game. It reads
 * player names, identifiers, and scores, and allocates memory for each player's data including
 * their penguins. When the specified team name is missing from the file, it adds a placeholder
 * entry for the team. The function also ensures that the input data conforms to the expected
 * format and handles errors such as invalid player IDs or memory allocation failures.
 *
 * @param game_state A pointer to the GameState structure where the player data will be loaded.
 *                   This structure must be pre-initialized before calling the function.
 * @param input_file A pointer to a file stream, already opened for reading, that contains the
 *                   player data to be parsed. The file must follow the defined format.
 */
void loadPlayers(struct GameState *game_state, FILE *input_file);

#endif //PROJECT_AUTONOMOUS_MODE_H
