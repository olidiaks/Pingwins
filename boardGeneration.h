//
// Created by theVo on 19/11/2025.
//

#ifndef PROJECT_BOARDGENERATION_H
#define PROJECT_BOARDGENERATION_H

#include <stdio.h>

/**
 * @brief Reads the board dimensions.
 *
 * This function reads the dimensions of the game board, likely from standard input or a configuration source.
 * It initializes the board size variables used throughout the game.
 */
void readBoardDimensions(void);

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