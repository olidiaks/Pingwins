//
// Created by olidiaks on 17.12.2025.
//

#ifndef PROJECT_AUTONOMUS_PLACEMENT_H
#define PROJECT_AUTONOMUS_PLACEMENT_H


#include <limits.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "autonomousMode.h"
#include "binnaryTree.h"

/**
 * Counts the number of penguins placed on the board for the current player
 * and verifies if the desired number of penguins has been placed.
 *
 * @param gameState Pointer to the GameState structure representing the current state of the game.
 * @param numOfPengiuns The total number of penguins the current player is expected to place on the board.
 */
void countPenguins(struct GameState *gameState, int numOfPengiuns);

/**
 * Executes the autonomous placement phase in the game by reading the input file
 * to initialize the game state, counting the penguins placed by the current player,
 * and automatically placing remaining penguins on the board.
 * The final board state is then written to the output file.
 *
 * @param gameState Pointer to the GameState structure that holds the current state of the game.
 * @param inputFilePath File path of the input file containing the initial game configuration.
 * @param outputFilePath File path where the final game state will be written.
 * @param nameOfUs The name of the current team performing the autonomous placement.
 * @param num_of_penguins Array representing the number of penguins to be placed during this phase.
 */
void autonomousPlacement(struct GameState *gameState, char inputFilePath[], char outputFilePath[], char nameOfUs[],
                         char num_of_penguins[]);

/**
 * Automatically places a penguin on the board for the current player by selecting
 * the optimal location based on a scoring function. The method evaluates all eligible
 * positions and places the penguin at the position that yields the highest score.
 * If no valid placement is found, the program terminates.
 *
 * @param gameState Pointer to the GameState structure representing the current state of the game,
 * including the board, players, and placement configuration.
 */
void placePenguinAutomatically(struct GameState *gameState);

/**
 * Evaluates the score for placing a penguin at a specified position on the board,
 * considering the number of accessible fish and depth of possible moves.
 *
 * @param game_state Pointer to the GameState structure representing the current game state.
 * @param x The x-coordinate of the position to evaluate for the penguin placement.
 * @param y The y-coordinate of the position to evaluate for the penguin placement.
 * @param binaryTree Pointer to a binary tree structure used to store visited positions.
 * @param depth The maximum depth to search for additional moves from the given position.
 * @return The total score for placing a penguin at the specified position based on
 *         the number of accessible fish within the given depth.
 */
int scorePlacement(struct GameState *game_state, int x, int y, struct Node *binaryTree, int depth);

/**
 * @struct ThreadData
 * @brief Arguments and result storage for worker threads in the penguin placement algorithm.
 *
 * This structure is used to pass the game state and the specific range of board rows
 * (from startX to endX) that a thread is responsible for analyzing. It also serves
 * as the container for the results (best move coordinates and score) found by that
 * specific thread, allowing the main thread to aggregate results later.
 */
struct ThreadData {
    struct GameState *gameState;
    int startX;
    int endX;
    int x;
    int y;
    int bestScore;
    int threadId;
};

void *findBestMoveWorker(void *arg);

#endif //PROJECT_AUTONOMUS_PLACEMENT_H
