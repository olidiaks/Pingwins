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
 * Represents a player in the game and tracks their current state.
 *
 * This structure encapsulates essential player-related attributes and their current position
 * in the game for managing game logic and interactions.
 *
 * Members:
 * - id: An integer representing the unique identifier for the player.
 * - current_score: An integer storing the current score of the player.
 * - current_penguin: An integer representing the index of the penguin the player last interacted with.
 * - penguins: A pointer to an array of `Penguin` structures associated with the player.
 * - x: An integer indicating the current x-coordinate of the player's position.
 * - y: An integer indicating the current y-coordinate of the player's position.
 */
struct Player {
    int currentScore;
    int currentPenguin;
    struct Penguin *penguins;
    int x;
    int y;
};

/**
 * Represents the penguins of a player
 *
 * This structure stores the essential information related to a player's penguins
 * and ongoing progress within the game.
 *
 * Members:
 * - x,y:
 */
struct Penguin {
    int x,y;
};

/**
 * Represents the state of the game, including the board, players, and current progress.
 *
 * This structure contains information about the current player, the game board,
 * the list of players, the number of players participating, and the dimensions
 * of the board. It serves as the central data structure for managing the game's
 * state during its execution.
 *
 * Members:
 * - current_player: An integer representing the index of the player whose turn it is.
 * - Board: A two-dimensional array of `Field` structures representing the game board.
 * - Players: A pointer to an array of `Player` structures containing player-specific data.
 * - num_of_players: An integer indicating the number of players currently in the game.
 * - x_Board_size: The width of the game board (number of rows).
 * - y_Board_size: The height of the game board (number of columns).
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
 * Initializes the game state by setting up player information and initial game configuration.
 *
 * This function allocates memory for players and their respective penguins,
 * and initializes relevant data such as number of players, current player,
 * and the number of penguins per player. It establishes the foundation required
 * for conducting further game phases.
 *
 * Postconditions:
 * - `gameState.num_of_players`: Set to 2 by default.
 * - `gameState.current_player`: Set to 0 as the starting player.
 * - `gameState.num_of_penguins_per_player`: Set to 1.
 * - Memory is allocated for `gameState.Players` and their penguins, and
 *   relevant fields like `current_score` and `id` are initialized.
 */
void init();

void askInitQuestions();

#endif //PROJECT_GAMESTRUCTURE_H
