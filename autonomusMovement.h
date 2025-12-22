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
 * Handles the autonomous movement phase of the game by reading the current
 * game state from a specified input file, processing it, and writing updates
 * back to an output file.
 *
 * This function reads the game state data, processes movements based on the
 * game's rules, and saves the updated state to the output file. It ensures
 * proper management of file I/O, error handling, and data integrity when
 * interacting with the game state.
 *
 * @param gameState A pointer to the GameState structure that holds the current
 *                  state of the game, including the board, players, and related information.
 * @param inputFilePath A null-terminated string specifying the file path for the
 *                      input file containing the game state to be read.
 * @param outputFilePath A null-terminated string specifying the file path for
 *                       the output file where the updated game state will be written.
 * @param nameOfUs A null-terminated string specifying the team's name, which is
 *                 used for identifying the autonomous player performing the movements.
 */
void autonomousMovement(struct GameState *gameState, char inputFilePath[], char outputFilePath[], char nameOfUs[]);


/**
 * Moves the current player's penguin automatically to a valid position on the board.
 *
 * The function attempts to move the penguin based on random coordinates until a valid
 * move is found, adhering to the game rules. It updates the penguin's position,
 * places the penguin on the board, and collects fish from the new tile.
 *
 * @param gameState A pointer to the GameState structure containing the board state,
 *                  player data, and other game-related information. The function modifies
 *                  this structure by updating the current player's penguin position
 *                  and associated game state.
 */
void movePenguinAutomaticli(struct GameState *gameState);

#endif // PROJECT_AUTONOMUSMOVEMENT_H
