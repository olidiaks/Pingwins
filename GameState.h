//
// Created by olidiaks on 1.12.2025.

#ifndef PROJECT_GAMESTRUCTURE_H
#define PROJECT_GAMESTRUCTURE_H

/**
 * Represents a single field on the game board, tracking its attributes and player interaction.
 *
 * This structure encapsulates information about an individual field within the game board.
 * It manages resource availability and player-specific data related to the field.
 *
 * Members:
 * - amount_of_fish: An integer indicating the number of fish available on the field.
 * - id_player1: An integer identifying the player currently associated with the field.
 */
struct Field {
    int amount_of_fish;
    int id_player;
};


/**
 * Represents a player in the game, including their unique identifier and current score.
 *
 * This structure stores the essential information related to a player's identity
 * and ongoing progress within the game. The `id` uniquely identifies each player,
 * while the `current_score` tracks their accumulated score during gameplay.
 *
 * Members:
 * - id: An integer uniquely identifying the player within the game.
 * - current_score: An integer tracking the player's score accumulated during gameplay.
 */
struct Player {
    int id;
    int current_score;
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
 * - x_Board_size: The width of the game board (number of columns).
 * - y_Board_size: The height of the game board (number of rows).
 */
struct GameState {
    int current_player;
    struct Field **Board;
    struct Player *Players;
    int num_of_players;
    int x_Board_size;
    int y_Board_size;
};

/**
 * Initializes the game state structure with default values.
 *
 * This function initializes the number of players, sets their initial scores to zero,
 * and assigns unique IDs to each player within the game state. It does not perform
 * other game setup operations such as initializing the board or configuring additional
 * game parameters.
 */
void init();

#endif //PROJECT_GAMESTRUCTURE_H
