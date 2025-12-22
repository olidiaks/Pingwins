//
// Created by olidiaks on 17.12.2025.
//

#ifndef PROJECT_AUTONOMUSMOVEMENT_H
#define PROJECT_AUTONOMUSMOVEMENT_H

#include "autonomousMode.h"
#include  "GameState.h"

/**
 * Executes a player's move on the game board and updates the game state.
 *
 * The function updates the player's position and reflects the movement
 * by modifying the respective fields on the game board. Additionally,
 * it handles fish collection for the current player and prints a success
 * message upon completing the move.
 *
 * @param gameState A pointer to the GameState structure containing the
 *                  current game information, including the board, players,
 *                  and active player.
 * @param currentX  The x-coordinate of the player's new position on the board.
 * @param currentY  The y-coordinate of the player's new position on the board.
 * @param lastX     The x-coordinate of the player's previous position on the board.
 * @param lastY     The y-coordinate of the player's previous position on the board.
 */
void execute_player_move(struct GameState *gameState, int currentX, int currentY, int lastX, int lastY);


/**
 * Executes the autonomous movement of the player's penguins in the game.
 *
 * This function automates the process of reading the game state from an input
 * file, executing movements for the current player's penguins, and writing the
 * updated game state to an output file. It also ensures proper handling of input
 * and output files and applies the movement logic for penguins based on the game
 * state and rules.
 *
 * @param gameState A pointer to the GameState structure containing the current
 *                  game state, including the game board, players, and penguins.
 * @param inputFilePath A character array specifying the path to the input file
 *                      containing the initial game state.
 * @param outputFilePath A character array specifying the path to the output file
 *                       where the updated game state will be written.
 * @param nameOfUs A character array containing the name of the team executing
 *                 the autonomous movement.
 */
void autonomousMovement(struct GameState *gameState, char inputFilePath[], char outputFilePath[], char nameOfUs[]);


/**
 * Moves the specified player's penguin automatically to an adjacent tile
 * based on predefined rules and the current state of the game board.
 *
 * The function iterates through the game board to locate the active player's
 * penguin. Once found, it checks adjacent tiles to identify possible moves
 * where the tile contains fish and is unoccupied. If a valid move is found,
 * the penguin is moved to the target tile, and the game state is updated
 * accordingly. If no valid moves are available, the function exits with an error message.
 *
 * @param gameState A pointer to the GameState structure containing the
 *                  current game data, including the board, players, and
 *                  the active player information.
 */
void movePenguinAutomaticli(struct GameState *gameState);

#endif // PROJECT_AUTONOMUSMOVEMENT_H
