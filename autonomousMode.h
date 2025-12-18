//
// Created by olidiaks on 10.12.2025.
//

#ifndef PROJECT_AUTONOMOUS_MODE_H
#define PROJECT_AUTONOMOUS_MODE_H

#include <stdio.h>
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

FILE *openInputFileAndHandleError(char *filePath);

char readFile(FILE *givenFile);

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
