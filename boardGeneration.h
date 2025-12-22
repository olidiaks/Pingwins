//
// Created by theVo on 19/11/2025.
//

#ifndef PROJECT_BOARDGENERATION_H
#define PROJECT_BOARDGENERATION_H

#include <stdio.h>
#include "GameState.h"
#include <stdbool.h>
#include <stdlib.h>


/**
 * @brief Reads and validates the dimensions of the game board from user input.
 *
 * This function prompts the user to input the dimensions (number of rows and columns)
 * for the game board. It verifies that the provided dimensions are positive integers
 * using the isBoardDimensionsValid function. If the input is invalid, the function
 * displays an error message and prompts the user again until valid input is provided.
 *
 * @param gameState A pointer to the GameState structure where the board dimensions
 * will be stored.
 */
void readBoardDimensions(struct GameState *gameState);

/**
 * @brief Validates the dimensions of the game board stored in the GameState structure.
 *
 * This function checks if the board dimensions specified in the GameState structure
 * are positive integers. It prints an error message if the dimensions are invalid.
 *
 * @param gameState A pointer to the GameState structure containing the board dimensions.
 * @return Returns true if both dimensions are greater than 0; otherwise, returns false.
 */
bool isBoardDimensionsValid(struct GameState *gameState);

/**
 * @brief Generates a random game board and initializes its fields.
 *
 * This function allocates memory and populates the game board represented by a 2D array
 * of Field structures. Each field on the board is initialized with default values
 * and a random amount of fish (1, 2, or 3) based on defined probabilities.
 * If memory allocation fails at any point, the program exits with an error message.
 *
 * @param gameState A pointer to the GameState structure containing the board size
 * (xBoardSize and yBoardSize) and where the generated board will be stored.
 */
void generateBoard(struct GameState* gameState);

/**
 * @brief Initializes the game board with void fields.
 *
 * Allocates memory for a 2D game board based on the specified dimensions in the
 * GameState structure. Each field on the board is initialized with default values,
 * representing an empty state: no player, no penguin, and zero fish. If memory allocation
 * fails at any stage, the program will terminate, reporting an error.
 *
 * @param gameState A pointer to the GameState structure containing the board dimensions
 * (xBoardSize and yBoardSize) and a pointer to the allocated board where it will be stored.
 */
void generateVoidBoard(struct GameState* gameState);

#endif //PROJECT_BOARDGENERATION_H