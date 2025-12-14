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

void readFile(char*[]);

void autonomous_placement(struct GameState* gameState, char input_file_name[], char output_file_name[]);

void autonomous_movement(struct GameState* gameState, char input_file_name[], char output_file_name[]);

/**
 * Opens an input file in read mode, checks for errors, and handles them appropriately.
 *
 * If the file cannot be opened (e.g., due to an incorrect path or insufficient
 * permissions), the function will print an error message and terminate the program
 * with an exit code of 3.
 *
 * @param input_file_name The name or path of the input file to be opened.
 * @return A pointer to the opened input file.
 * @throws Exits the program on error with exit code 3, and prints an error message.
 */
FILE* open_input_file_and_handle_error(char* input_file_name);

/**
 * Opens an output file in write mode, checks for errors, and handles them appropriately.
 *
 * If the file cannot be opened (e.g., due to an incorrect path or insufficient
 * permissions), the function will print an error message and terminate the program
 * with an exit code of 3.
 *
 * @param output_file_name The name or path of the output file to be opened.
 * @return A pointer to the opened output file.
 * @throws Exits the program on error with exit code 3, and prints an error message.
 */
FILE* open_output_file_and_handle_error(char* output_file_name);

#endif //PROJECT_AUTONOMOUS_MODE_H
