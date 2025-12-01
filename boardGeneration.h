//
// Created by theVo on 19/11/2025.
//

#ifndef PROJECT_BOARDGENERATION_H
#define PROJECT_BOARDGENERATION_H

#include <stdio.h>
#include "GameState.h"
#include <stdbool.h>
#include <stdlib.h>

extern struct GameState gameState;

/**
 * @brief Reads and validates the dimensions of the game board.
 *
 * This function prompts the user to input the dimensions of the game board
 * and ensures the input consists of two valid integers. It repeatedly asks
 * for valid input until correct values are provided. The validity of the
 * dimensions is determined by the isBoardDimensionsValid function.
 *
 * The dimensions are stored in the global GameState structure.
 */
void readBoardDimensions(void);

/**
 * @brief Validates the board dimensions.
 *
 * This function checks whether the dimensions of the game board are valid.
 * It ensures the width and height of the board are both positive integers.
 * It prints an error message when coordinates are invalid.
 *
 * @return true if the board dimensions are valid, false otherwise.
 */
bool isBoardDimensionsValid(void);

/**
 * @brief Generates a random board configuration.
 *
 * This function creates a board with randomly placed elements (e.g., fish, penguins)
 * based on the board dimensions specified by the caller. The exact nature of the
 * randomization depends on the implementation details of the board generation logic.
 *
 * The function does not return any value and does not take any parameters.
 */
void generateRandomBoard(void);

#endif //PROJECT_BOARDGENERATION_H