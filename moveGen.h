//
// Created by theVo on 1/5/2026.
//

#ifndef PROJECT_MOVEGEN_H
#define PROJECT_MOVEGEN_H

#include "GameState.h"

/**
 * @struct Move
 * @brief Represents a single move in the game.
 *
 * This structure holds information regarding a player's move, including the
 * player ID, the penguin involved, the starting and destination coordinates,
 * and the value of the move.
 *
 * Attributes:
 * @var `playerId`: The ID of the player who made the move.
 * @var `penguinIdx`: The index of the penguin involved in the move.
 * @var `fromX`: The x-coordinate of the starting position of the move.
 * @var `fromY`: The y-coordinate of the starting position of the move.
 * @var `toX`: The x-coordinate of the destination position of the move.
 * @var `toY`: The y-coordinate of the destination position of the move.
 * @var `moveValue`: The evaluated value of the move, used for scoring or AI decision-making.
 */
struct Move {
    int playerId;
    int penguinIdx;

    int toX;
    int toY;

    int fromX;
    int fromY;

    int moveValue;
};

/**
 * @brief Determines if a specific tile on the game board is free.
 *
 * This function checks if a tile at the given coordinates is free to move onto
 * by verifying that the tile contains fish (amountOfFish > 0) and does not currently
 * hold a penguin (idPenguin == -1).
 *
 * @param gs A pointer to the current game state, which includes the board configuration and other game details.
 * @param x The x-coordinate of the tile to check.
 * @param y The y-coordinate of the tile to check.
 * @return 1 if the tile is free to move onto, 0 otherwise.
 */
int isTileFree(struct GameState *gs, int x, int y);

/**
 * @brief Counts the total number of possible moves for a given penguin on the board.
 *
 * This function evaluates the available number of moves a specified penguin can make
 * in all four cardinal directions (up, down, left, right) on the board. It considers
 * only valid moves where the destination tile is free, stopping when an obstacle or
 * the edge of the board is encountered. The function is primarily used for determining
 * mobility during gameplay and AI decision-making.
 *
 * @param gs A pointer to the current game state, which contains the board and player data.
 * @param playerId The ID of the player whose penguin is being evaluated.
 * @param penguinIndex The index of the penguin within the player's collection.
 * @param x The x-coordinate of the penguin's current position on the board.
 * @param y The y-coordinate of the penguin's current position on the board.
 * @return The total number of valid moves the penguin can make from its current position.
 */
int countPossibleMoves(struct GameState *gs, int playerId, int penguinIndex, int x, int y);

/**
 * @brief Evaluates the current state of the game board and computes a score.
 *
 * This function calculates a score for the given game state by analyzing
 * the current player's resources, including their harvested fish and possible moves,
 * and comparing it with the opponent's best achievable score.
 * The evaluation uses defined weights for fish and mobility to prioritize scoring
 * and strategic positioning.
 *
 * @param gs A pointer to the GameState structure representing the current state
 *           of the game, including players, the board, and penguins' positions.
 * @return An integer value representing the relative score of the game state
 *         for the current player. A positive score favors the current player,
 *         while a negative score favors the opponents.
 */
int evaluateBoard(struct GameState *gs);

/**
 * @brief Creates and registers a move for a specified penguin in the game state.
 *
 * This function generates a move object representing the movement of a given penguin
 * from its current position to a specified destination. The move includes details
 * about the player, penguin, starting position, destination position, and the move value.
 *
 * @param gs A pointer to the GameState structure representing the current state of the game.
 * @param plrId The ID of the player who is making the move.
 * @param penguinIndex The index of the penguin being moved.
 * @param x The x-coordinate of the destination position.
 * @param y The y-coordinate of the destination position.
 * @return A Move structure containing the details of the registered move, including
 *         the starting and destination coordinates and other relevant move details.
 */
struct Move registerMove(struct GameState *gs, int plrId, int penguinIndex, int x, int y);

/**
 * @brief Generates all legal moves for a specific player and their penguins.
 *
 * This function identifies all possible moves that a player can make with their penguins
 * based on the current state of the game. The generated moves are stored in a dynamically
 * allocated array of `Move` structures, which the caller is responsible for freeing.
 *
 * @param gs A pointer to the current game state structure containing all game data.
 * @param count A pointer to an integer where the function will store the count of legal moves generated.
 * @param playerId The ID of the player for whom the legal moves are to be generated.
 * @return A pointer to a dynamically allocated array of `Move` structures representing all legal moves.
 *         The caller is responsible for freeing the allocated memory.
 */
struct Move* generateAllLegalMoves(struct GameState *gs, int *count, int playerId);

#endif //PROJECT_MOVEGEN_H