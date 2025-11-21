//
// Created by theVo on 19/11/2025.
//

#ifndef PROJECT_PLAYERACTIONS_H
#define PROJECT_PLAYERACTIONS_H


#include "main.h"
#include "stdio.h"
#include "stdlib.h"

/**
 * @brief Collects fish for the current player.
 *
 * This function updates the game state by collecting fish for the current player.
 * It also outputs a message indicating that the current player has collected fish.
 */
void collectFish(void);

/**
 * @brief Sets the current player to player 0.
 */
void setCurrentPlayer(void);

/**
 * @brief Changes the current player in the game.
 *
 * This function toggles the current player between two players.
 * It updates the game state by switching to the next player.
 * A message is printed indicating the player change.
 */
void changeCurrentPlayer(void);

/**
 * @brief Asks the current player for coordinates input.
 *
 * This function prompts the current player to enter coordinates for placing a penguin or moving a penguin.
 * It is called during the placement phase and movement phase of the game.
 */
void askCoordinates(void);

/**
 * @brief Checks if the current move is valid.
 *
 * This function checks if the current move is valid.
 * It returns true if the move is valid, false otherwise.
 */
bool isMoveValid(void);

#endif //PROJECT_PLAYERACTIONS_H