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
 * @brief Reads and validates the dimensions of the game board.
 *
 * This function prompts the user to input the dimensions of the game board
 * and ensures the input consists of two valid integers. It repeatedly asks
 * for valid input until correct values are provided. The validity of the
 * dimensions is determined by the isBoardDimensionsValid function.
 *
 * The dimensions are stored in the global GameState structure.
 * @param gameState A pointer to the GameState structure containing the board dimensions.
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
 * @brief Generates a random game board and initializes each field.
 *
 * This function dynamically allocates memory for the game board
 * based on the dimensions specified in the GameState structure
 * (x_Board_size and y_Board_size). It then initializes each field
 * on the board with a random number of fish and sets the player ID to -1
 * (indicating no player is present in that field).
 *
 * @param gameState Pointer to the GameState structure that holds the
 *        board dimensions and other game-related information. The function
 *        modifies the GameState to include the newly generated board.
 */
void generateBoard(struct GameState* gameState);

#endif //PROJECT_BOARDGENERATION_H