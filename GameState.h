//
// Created by olidiaks on 1.12.2025.

#ifndef PROJECT_GAMESTRUCTURE_H
#define PROJECT_GAMESTRUCTURE_H

#include <stdio.h>
#include <stdlib.h>

/**
 * Represents a single field on the game board and its current state.
 *
 * This structure tracks the attributes of an individual field, including the
 * amount of fish available on the field, and any player or penguin associated with it.
 *
 * Members:
 * - amount_of_fish: An integer indicating the number of fish currently present on the field.
 * - id_player: An integer representing the ID of the player occupying the field or -1 if unoccupied.
 * - id_penguin: An integer representing the ID of the penguin on the field or -1 if no penguin is present.
 */
struct Field {
    int amountOfFish;
    int idPlayer;
    int idPenguin;
};


/**
 * Represents a player in the game and their associated attributes.
 *
 * This structure keeps track of essential information about a player's current
 * state within the game, including their score, penguins, position, and name.
 *
 * Members:
 * - currentScore: An integer representing the total score of the player, based on the fish collected.
 * - currentPenguin: An integer indicating the index of the penguin currently being controlled by the player.
 * - penguins: A dynamic array of `Penguin` objects representing the player's penguins in the game.
 * - x: An integer representing the current x-coordinate of the location being interacted with by the player.
 * - y: An integer representing the current y-coordinate of the location being interacted with by the player.
 * - name: A dynamically allocated string representing the name of the player.
 */
struct Player {
    int currentScore;
    int currentPenguin;
    struct Penguin *penguins;
    int x;
    int y;
    char *name;
};

/**
 * Represents a Penguin with its position on the game board.
 *
 * This structure is used to track the position of an individual penguin
 * within the game. Each penguin is associated with a specific player and
 * is identified by its coordinates on the game board.
 *
 * Members:
 * - x: An integer representing the x-coordinate of the penguin's position on the board.
 * - y: An integer representing the y-coordinate of the penguin's position on the board.
 */
struct Penguin {
    int x, y;
};

/**
 * Represents the overall state of the game at any given moment.
 *
 * This structure contains all the critical information and parameters required
 * to manage and track the progress of the game, including players, board configuration,
 * and game-specific settings.
 *
 * Members:
 * - teamName: A pointer to a null-terminated string representing the name of the current team.
 * - currentPlayer: An integer representing the index of the player who is currently taking their turn.
 * - Board: A 2D dynamic array of Field structures representing the game board.
 * - Players: A dynamic array of Player structures representing all players participating in the game.
 * - numOfPlayers: The number of players currently playing the game.
 * - xBoardSize: The number of columns on the game board.
 * - yBoardSize: The number of rows on the game board.
 * - numOfPenguinsPerPlayer: The number of penguins allocated for each player.
 */
struct GameState {
    char *teamName;
    int currentPlayer;
    struct Field **Board;
    struct Player *Players;
    int numOfPlayers;
    int xBoardSize;
    int yBoardSize;
    int numOfPenguinsPerPlayer;
};

/**
 * Initializes the game state by setting up players, their attributes,
 * and allocating memory for penguins and other game-related structures.
 *
 * This method prepares the game state for the beginning of the game by:
 * - Assigning the team name.
 * - Prompting the user with initialization questions.
 * - Setting the current player to the initial player.
 * - Allocating and initializing memory for players and their associated penguins.
 *
 * If memory allocation for penguin structures fails due to insufficient memory,
 * it will terminate the program with an error code.
 */
void init();

/**
 * Prompts the user to input the initial game settings, including the number
 * of players and the number of penguins per player.
 *
 * This function collects critical information to initialize the game state.
 * The user is repeatedly asked valid inputs for the number of players
 * (between 2 and 9) and the number of penguins per player (between 1 and 9)
 * until acceptable values are entered.
 *
 * The collected values are stored in the global gameState structure:
 * - numOfPlayers: The total number of players in the game.
 * - numOfPenguinsPerPlayer: The number of penguins each player controls.
 */
void askInitQuestions();

/**
 * Creates a deep copy of the given game state.
 *
 * This function duplicates the entire structure of the game state, including all nested fields,
 * players, penguins, and the game board. It ensures that changes made to the cloned game state
 * do not affect the original game state and vice versa.
 *
 * Parameters:
 * - gameState: A pointer to the `GameState` structure to be cloned. The input must be a valid
 *              and fully initialized `GameState` instance.
 *
 * Returns:
 * - A pointer to a new `GameState` structure that is a complete deep copy of the input game state.
 *   Memory for the new structure and its associated sub-structures is dynamically allocated.
 *   The caller is responsible for freeing this memory when it is no longer needed.
 *
 * Notes:
 * - The function dynamically allocates memory for players, the game board, and penguins.
 *   Ensure that proper memory management is done to deallocate the resources when no longer
 *   in use to prevent memory leaks.
 * - The structure returned by this function is independent of the original, and modifications
 *   to one will not affect the other.
 */
struct GameState *deepCloneGameState(struct GameState *gameState);

#endif // PROJECT_GAMESTRUCTURE_H
