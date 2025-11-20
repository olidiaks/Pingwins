//
// Created by theVo on 19/11/2025.
//

#ifndef PROJECT_MOVEMENT_H
#define PROJECT_MOVEMENT_H

#include <stdbool.h>
#include "playerActions.h"
#include "consoleVisualization.h"
#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void movementPhase(void);

/**
 * This function check if any player can make move.
 * @return Return true if penguin can be placed and false if not.
 */
bool isThereAnyPenguinMoveAvailable(void);

/**
 * This function check if player can make move.
 * @return Return true if player can move and false if can't.
 */
bool isPlayerMoveAvailable(void);

/**
 *
 */
void movePenguin(void);

#endif //PROJECT_MOVEMENT_H