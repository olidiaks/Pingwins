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
 * Represents the state of the game at any given point in time.
 *
 * This structure contains all the critical information required to represent
 * the current status of the game, including the board configuration, players,
 * and gameplay parameters.
 *
 * Members:
 * @var teamName: A pointer to a character array representing the name of the team
 * @var  controlling this instance of the game.
 * @var currentPlayer: An integer representing the index of the player who is
 *      currently taking their turn.
 * @var Board: A pointer to a 2D array of Field structures representing the game
 *   board, where each field has its own attributes and state.
 * @var Players: A pointer to an array of Player structures containing information
 *   about all players participating in the game.
 * @var numOfPlayers: An integer indicating the total number of players in the game.
 * @var xBoardSize: An integer representing the horizontal size of the game board.
 * @var yBoardSize: An integer representing the vertical size of the game board.
 * @var numOfPenguinsPerPlayer: An integer specifying the number of penguins
 *   allocated to each player in the game.
 * @var numbOfTilesWithOneTile: An integer counting how many tiles are with one fish for placement phase. Later integer is not updated.
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
    int numbOfTilesWithOneFish;
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
 * Initializes the game settings by prompting the user for input.
 *
 * This function interacts with the user to gather essential game configuration details,
 * including the number of players and the number of penguins per player. Input is validated
 * to ensure it falls within the permissible range:
 * - Number of players: between 2 and 9.
 * - Number of penguins per player: between 1 and 9.
 *
 * Updates:
 * - `gameState.numOfPlayers`: Stores the validated number of players.
 * - `gameState.numOfPenguinsPerPlayer`: Stores the validated number of penguins per player.
 *
 * Ensures that the game initialization starts with correct and user-validated parameters.
 */
void askInitQuestions();

/**
 * Creates a deep copy of the given game state.
 *
 * This function performs a deep clone of the provided GameState structure,
 * including all nested objects such as the game board, players, and penguins.
 * The resulting cloned structure is independent of the original game state,
 * meaning changes to the clone will not affect the original.
 *
 * @param gameState A pointer to the GameState structure to be cloned.
 * @return A pointer to the newly created deep copy of the specified GameState.
 */
struct GameState *deepCloneGameState(struct GameState *gameState);

/**
 * Frees all allocated memory associated with the given GameState.
 *
 * This function deallocates the memory for the game board, all players, and their associated penguins.
 * It should be called when the GameState is no longer needed to ensure proper cleanup of resources
 * and prevent memory leaks.
 *
 * @param gameState A pointer to the GameState object to be freed. The structure must have been
 *                  previously allocated and properly initialized.
 * @return void
 */
void freeGameState(struct GameState *gameState);

#endif // PROJECT_GAMESTRUCTURE_H
